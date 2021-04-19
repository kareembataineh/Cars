#include "CarSearch.h"

using namespace std;
using namespace std::chrono;

int main() {

    CarSearch cars;
    cars.generateData("vehicles.csv");
    cars.printSize();
    cars.Search();

    //cars.treeSortLowToHigh();
    //cars.treeSortHighToLow();

    auto start = high_resolution_clock::now();
    cars.heapSortLowToHigh(cars.getOutput());
    auto end = high_resolution_clock::now();
    auto time = duration_cast<milliseconds>(end-start);
    cout << "Heapsort time: (low to high) " << time.count() << " ms" << endl;

    start = high_resolution_clock::now();
    cars.heapSortHighToLow(cars.getOutput());
    end = high_resolution_clock::now();
    time = duration_cast<milliseconds>(end-start);
    cout << "Heapsort time: (high to low) " << time.count() << " ms" << endl;

    start = high_resolution_clock::now();
    cars.mergesortLowToHigh(cars.getOutput());
    end = high_resolution_clock::now();
    time = duration_cast<milliseconds>(end-start);
    cout << "Mergesort time: (low to high) " << time.count() << " ms" << endl;

    start = high_resolution_clock::now();
    cars.mergesortHighToLow(cars.getOutput());
    end = high_resolution_clock::now();
    time = duration_cast<milliseconds>(end-start);
    cout << "Mergesort time: (high to low) " << time.count() << " ms" << endl;

    cars.printLinks(cars.mergesortLowToHigh(cars.getOutput()));

    return 0;
}
