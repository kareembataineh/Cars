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

std::vector<Car*> mergeLowToHigh(std::vector<Car*> list1, std::vector<Car*> list2);
std::vector<Car*> mergeHighToLow(std::vector<Car*> list1, std::vector<Car*> list2);


class CarSearch {

private:
    std::unordered_map<int, Car*> table; //data table
    std::vector<Car*> output; //output to be shown to user

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
    int treeSortLowToHigh();
    int treeSortHighToLow();
    std::vector<Car*> heapSortLowToHigh(std::vector<Car*> unsortedResults);
    std::vector<Car*> heapSortHighToLow(std::vector<Car*> unsortedResults);
    std::vector<Car*> mergesortLowToHigh(std::vector<Car*> list);
    std::vector<Car*> mergesortHighToLow(std::vector<Car*> list);
    std::vector<Car*> radixSortLowToHigh(std::vector<Car*>& unsorted);
    std::vector<Car*> radixSortHighToLow(std::vector<Car*>& unsorted);
    const std::vector<Car*> &getOutput() const;
};
