#include "CarSearch.h"
#include "minHeap.h"
#include "maxHeap.h"

using namespace std;
using namespace std::chrono;

void CarSearch::generateData(string dataset) {
    //Creates a table with all of the data
    ifstream ifs(dataset);
    string s;
    Car* car;

    getline(ifs, s);

    while (getline(ifs, s)) {
        car = createCar(s);
        if (car != NULL) {
            table[car->idNum] = car;
        }
    }
}

Car* CarSearch::createCar(string data) {
    //Creates a Car object from a string of data
    if (!isdigit(data[0]))
        return NULL;

    stringstream ss(data);
    string str, temp;
    Car* car = new Car;
    vector<string> dataList;

    while(ss.good())
    {
        getline( ss, str, ',' );
        dataList.push_back(str);
    }

    for (int i = 0; i < dataList.size(); ++i) {

        while (dataList[i][0] == '"' && (dataList[i][dataList[i].size()-1] != '"' || dataList[i].size() == 1)) {
            dataList[i] += dataList[i+1];
            for (int j = i+1; j < dataList.size()-1; ++j) {
                dataList[j] = dataList[j+1];
            }
        }
    }

    if (dataList[0].size() > 6 || dataList[4].size() != 4)
        return NULL;

    car->idNum = stoi(dataList[0]);
    car->listingURL = dataList[2];
    car->price = stod(dataList[3]);
    if (dataList[4] != "" && dataList[4] != "\r")
        car->year = stoi(dataList[4]);
    else
        car->year = NULL;
    car->make = dataList[5];
    car->model = dataList[6];
    car->condition = dataList[7];
    if (dataList[8] != "" && dataList[8] != "\r")
        car->mileage = stoi(dataList[8]);
    else
        car->mileage = NULL;

    return car;

}

void CarSearch::printSize() {
    cout << "table size: " << table.size() << endl;
}


void CarSearch::Search(double lowPrice, double highPrice, int lowYear, int highYear, std::string make, std::string model,
                       std::string condition, int lowmiles, int highmiles) {
    //Finds all cars that match user's criteria
    auto start = high_resolution_clock::now();
    Car* temp;
    output.clear();

    for (auto it: table) {
        temp = it.second;
        if (temp->price > lowPrice && temp->price < highPrice && temp->year > lowYear
        && temp->year < highYear && temp->mileage > lowmiles && temp->mileage < highmiles) {
            if ((make != "" && temp->make != make) || (model != "" && temp->model != model)
                || (condition != "" && temp->condition != condition)) {
                continue;
            }
            output.push_back(temp);
        }
    }
    auto end = high_resolution_clock::now();
    auto time = duration_cast<milliseconds>(end-start);
    cout << "Selection time: " << time.count() << " ms" << endl;
}


void CarSearch::printLinks(std::vector<Car*> list) {

    ofstream ofs("listURLs.txt");

    ofs << "There are " << list.size() << " cars that meet your criteria:" << endl;
    for (int i = 0; i < list.size(); ++i) {
        ofs << list[i]->listingURL << endl;
    }
}

vector<Car*> CarSearch::heapSortLowToHigh(vector<Car*> unsortedResults) {
    //Sorts cars in ascending order by price with a min heap
    minHeap pq;
    vector<Car*> sorted;
    for (int i = 0; i < unsortedResults.size(); i++) {
        pq.insert(unsortedResults[i]);
    }
    while (!pq.empty()) {
        sorted.push_back(pq.top());
        pq.heapRemove();
    }
    return sorted;
}

vector<Car*> CarSearch::heapSortHighToLow(vector<Car*> unsortedResults) {
    //Sorts cars in descending order by price with a max heap
    maxHeap pq;
    vector<Car*> sorted;
    for (int i = 0; i < unsortedResults.size(); i++) {
        pq.insert(unsortedResults[i]);
    }
    while (!pq.empty()) {
        sorted.push_back(pq.top());
        pq.heapRemove();
    }
    return sorted;
}

int CarSearch::treeSortLowToHigh() {
    //Sorts cars in ascending order by price with a map (red-black tree)
    auto start = high_resolution_clock::now();
    map<double, vector<Car*>> map;
    for (int i = 0; i < output.size(); ++i) {
        map[output[i]->price].push_back(output[i]);
    }
    output.clear();
    for (auto it: map) {
        for (int i = 0; i < it.second.size(); ++i) {
            output.push_back(it.second[i]);
        }
    }
    auto end = high_resolution_clock::now();
    auto time = duration_cast<milliseconds>(end-start);
    cout << "Tree sort time: (low to high) " << time.count() << " ms" << endl;
    return time.count(); //Returns the time for this operation in milliseconds
}

int CarSearch::treeSortHighToLow() {
    //Sorts cars in descedning order by price with a map (red-black tree)
    auto start = high_resolution_clock::now();
    map<double, vector<Car*>> map;
    //AVLTree tree;
    for (int i = 0; i < output.size(); ++i) {
        map[output[i]->price].push_back(output[i]);
        //tree.insert(tree.getRoot(), output[i]);
    }
    output.clear();
    for (auto it = map.rbegin(); it != map.rend() ; ++it) {
        for (int i = 0; i < it->second.size(); ++i) {
            output.push_back(it->second[i]);
        }
    }
    //tree.inOrder(tree.getRoot(), output);
    auto end = high_resolution_clock::now();
    auto time = duration_cast<milliseconds>(end-start);
    cout << "Tree sort time: (high to low) " << time.count() << " ms" << endl;
    return time.count(); //Returns the time for this operation in milliseconds
}

vector<Car*> CarSearch::mergesortLowToHigh(vector<Car*> list) {
    //Sorts cars in ascending order by price with merge sort algorithm
    if (list.size() <= 1)
        return list;

    int length = list.size()/2;

    vector<Car*> list1(list.begin(), list.begin()+length);
    vector<Car*> list2(list.begin()+length, list.end());

    list1 = mergesortLowToHigh(list1);
    list2 = mergesortLowToHigh(list2);

    output = mergeLowToHigh(list1, list2);
    return output;
}

vector<Car*> mergeLowToHigh(vector<Car*> list1, vector<Car*> list2) {
    //Helper function for the merge sort
    vector<Car*> sortedList;

    while (!list1.empty() && !list2.empty()) {
        if (list1[0] > list2[0]) {
            sortedList.push_back(list2[0]);
            list2.erase(list2.begin());
        }
        else {
            sortedList.push_back(list1[0]);
            list1.erase(list1.begin());
        }
    }

    while (!list1.empty()) {
        sortedList.push_back(list1[0]);
        list1.erase(list1.begin());
    }

    while (!list2.empty()) {
        sortedList.push_back(list2[0]);
        list2.erase(list2.begin());
    }

    return sortedList;
}

vector<Car*> CarSearch::mergesortHighToLow(vector<Car*> list) {
    //Sorts cars in descending order by price with merge sort algorithm
    if (list.size() <= 1)
        return list;

    int length = list.size()/2;

    vector<Car*> list1(list.begin(), list.begin()+length);
    vector<Car*> list2(list.begin()+length, list.end());

    list1 = mergesortHighToLow(list1);
    list2 = mergesortHighToLow(list2);

    output = mergeHighToLow(list1, list2);
    return output;
}

vector<Car*> mergeHighToLow(vector<Car*> list1, vector<Car*> list2) {
    //Helper function for the merge sort
    vector<Car*> sortedList;

    while (!list1.empty() && !list2.empty()) {
        if (list1[0] < list2[0]) {
            sortedList.push_back(list2[0]);
            list2.erase(list2.begin());
        }
        else {
            sortedList.push_back(list1[0]);
            list1.erase(list1.begin());
        }
    }

    while (!list1.empty()) {
        sortedList.push_back(list1[0]);
        list1.erase(list1.begin());
    }

    while (!list2.empty()) {
        sortedList.push_back(list2[0]);
        list2.erase(list2.begin());
    }

    return sortedList;
}

void counterSort(vector<Car*>& v, int z)
{
    vector<Car*> answer;
    vector<int> counter;

    for (int i = 0; i < 10; i++)
    {
        counter.push_back(0);
    }

    for (int i = 0; i < v.size(); i++)
    {
        counter[(int(v[i]->price) / z) % 10]++;
        answer.push_back(nullptr);
    }

    for (int i = 1; i < 10; i++)
    {
        counter.at(i) += counter.at(i - 1);
    }



    for (int i = v.size() - 1; i >= 0; i--)
    {

        answer.at(counter.at((int(v[i]->price) / z) % 10) - 1) = v.at(i);
        counter[(int(v[i]->price) / z) % 10]--;
    }


    for (int i = 0; i < v.size(); i++)
    {
        if (answer.at(i) != nullptr)
        {
            v.at(i) = answer.at(i);
            //cout << v.at(i)->price << endl;
        }

    }
}

vector<Car*> CarSearch::radixSortLowToHigh(vector<Car*>& unsorted)
{
    vector<Car*> answer;

    int max = 0;
    for (int i = 0; i < unsorted.size(); i++)
    {
        if (unsorted.at(i)->price > max)
            max = unsorted.at(i)->price;
    }

    for (int i = 1; (max / i) > 0; i *= 10)
    {
        counterSort(unsorted, i);
    }

    answer = unsorted;
    return answer;
}

vector<Car*> CarSearch::radixSortHighToLow(vector<Car*>& unsorted)
{
    vector<Car*> answer;

    int max = 0;
    for (int i = 0; i < unsorted.size(); i++)
    {
        if (unsorted.at(i)->price > max)
            max = unsorted.at(i)->price;
    }

    for (int i = 1; (max / i) > 0; i *= 10)
    {
        counterSort(unsorted, i);
    }

    answer = unsorted;
    reverse(answer.begin(), answer.end());
    return answer;
}

const vector<Car*> &CarSearch::getOutput() const {
    return output;
}
