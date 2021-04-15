#include "CarSearch.h"

using namespace std;

int main() {

    CarSearch cars;
    cars.generateData("vehicles.csv");
    cars.printSize();
    cars.Search();

    cars.sortLowToHigh();
    cars.sortHighToLow();
    cars.printLinks(cars.getOutput());

    return 0;
}
