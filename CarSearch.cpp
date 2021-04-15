#include "CarSearch.h"

using namespace std;
using namespace std::chrono;

void CarSearch::generateData(string dataset) {

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

void CarSearch::sortLowToHigh() {

    auto start = high_resolution_clock::now();
    priority_queue<Car*, std::vector<Car*>, compareMin> minHeap;
    vector<Car*> sorted;
    for (int i = 0; i < output.size(); ++i) {
        minHeap.push(output[i]);
    }
    output.clear();
    while (!minHeap.empty()) {
        output.push_back(minHeap.top());
        minHeap.pop();
    }
    auto end = high_resolution_clock::now();
    auto time = duration_cast<milliseconds>(end-start);
    cout << "Heap sort time: (low to high) " << time.count() << " ms" << endl;
}

void CarSearch::sortHighToLow() {

    auto start = high_resolution_clock::now();
    priority_queue<Car*, std::vector<Car*>, compareMax> maxHeap;
    for (int i = 0; i < output.size(); ++i) {
        maxHeap.push(output[i]);
    }
    output.clear();
    while (!maxHeap.empty()) {
        output.push_back(maxHeap.top());
        maxHeap.pop();
    }
    auto end = high_resolution_clock::now();
    auto time = duration_cast<milliseconds>(end-start);
    cout << "Heap sort time: (high to low) " << time.count() << " ms" << endl;
}

const vector<Car*> &CarSearch::getOutput() const {
    return output;
}
