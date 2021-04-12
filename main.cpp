#include "CarSearch.h"

using namespace std;

int main() {

    CarSearch cars;
    cars.generateData("vehicles.csv");
    cars.printSizes();
    cars.printLinks(cars.getLinksFromTable(5000, 10000));
    //cars.printLinks(cars.getLinksFromTree());
    return 0;

}
