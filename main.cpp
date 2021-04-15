#include "CarSearch.h"

using namespace std;

int main() {

    CarSearch cars;
    cars.generateData("vehicles.csv");
    cars.printSize();
    cars.Search();

    cars.heapSortLowToHigh();
    cars.heapSortHighToLow();
    cars.treeSortLowToHigh();
    cars.treeSortHighToLow();
    cars.printLinks(cars.getOutput());

    return 0;
}
