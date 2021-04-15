#include <string>
#include <unordered_map>
#include <map>
#include <queue>
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
#include <chrono>
#pragma once

struct Car {
    double price;
    int year, mileage, idNum;
    std::string make, model, condition, listingURL;
};

struct compareMin {
    //Comparison for the Min heap
    bool operator()(Car* left, Car* right) {
        return left->price < right->price;
    }
};

struct compareMax {
    //Comparison for the Max heap
    bool operator()(Car* left, Car* right) {
        return left->price > right->price;
    }
};

class CarSearch {

private:
    std::unordered_map<int, Car*> table;
    std::vector<Car*> output;

public:
    void generateData(std::string dataset);
    Car* createCar(std::string data);
    void printSize();

    void Search(
            double lowPrice= 0, double highPrice= 1000000000,
            int lowYear= 0, int highYear= 3000,
            std::string make = "", std::string model= "", std::string condition= "",
            int lowmiles= 0, int highmiles= 1000000000
    );

    void printLinks(std::vector<Car*> list);
    void heapSortLowToHigh();
    void heapSortHighToLow();
    void treeSortLowToHigh();
    void treeSortHighToLow();
    const std::vector<Car*> &getOutput() const;
};
