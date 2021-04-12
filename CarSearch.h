//
// Created by Kareem Bataineh on 4/6/21.
//
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

struct compare {
    //Comparison for the priority queue
    bool operator()(Car* left, Car* right) {
        return left->price < right->price;
    }
};

class CarSearch {

private:
    std::unordered_map<int, Car*> table;
    std::map<int, Car*> tree;
    std::priority_queue<Car*, std::vector<Car*>, compare> heap;

public:

    void generateData(std::string dataset);
    Car* createCar(std::string data);
    void printSizes();

    std::vector<Car*> getLinksFromTable(
            double lowPrice= 0, double highPrice= 1000000000,
            int lowYear= 0, int highYear= 3000,
            const std::string make = "", const std::string model= "", const std::string condition= "",
            int lowmiles= 0, int highmiles= 1000000000
    );

    std::vector<Car*> getLinksFromTree(
            double lowPrice= 0, double highPrice= 1000000000,
            int lowYear= 0, int highYear= 3000,
            std::string make= "", std::string model= "", std::string condition= "",
            int lowmiles= 0, int highmiles= 1000000000
    );

    void printLinks(std::vector<Car*> list);

};