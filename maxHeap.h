#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include "math.h"
#include "CarSearch.h"

using namespace std;
#pragma once


class maxHeap {
private:
    vector<Car*> heap;


public:
    void heapifyDown(int parent);
    void heapRemove();
    Car* top();
    void heapifyUp(int i);
    void insert(Car* c);
    bool empty();
    int size();
    void print();


};

// balances the heap if property is violated
void maxHeap::heapifyDown(int parent)
{

    int left = (2 * parent) + 1;
    int right = (2 * parent) + 2;
    int min = parent;
    if (left < heap.size() && heap[left]->price > heap[min]->price)
    {
        min = left;
    }
    if (right < heap.size() && heap[right]->price > heap[min]->price)
    {
        min = right;
    }
    if (min != parent)
    {
        Car* temp = heap[min];
        heap[min] = heap[parent];
        heap[parent] = temp;
        return heapifyDown(min);
    }
}

// removes the car with lowest price from the heap
void maxHeap::heapRemove()
{
    heap[0] = heap[heap.size() - 1];
    heap.pop_back();
    heapifyDown(0);
}

// returns the car with the lowest price in the heap
Car* maxHeap::top()
{
    return heap[0];
}

// balances the heap if property is violated when inserting
void maxHeap::heapifyUp(int i)
{
    if (heap[(i - 1) / 2]->price < heap[i]->price)
    {
        Car* temp = heap[i];
        heap[i] = heap[(i - 1) / 2];
        heap[(i - 1) / 2] = temp;
        heapifyUp((i - 1) / 2);
    }
}

// inserts car into heap
void maxHeap::insert(Car* c)
{
    heap.push_back(c);
    int index = heap.size() - 1;
    heapifyUp(index);
}

bool maxHeap::empty()
{
    if (heap.size() != 0)
        return false;
    return true;
}

// prints the heap for testing purposes
void maxHeap::print()
{
    for (int i = 0; i < heap.size(); i++)
    {
        cout << heap.at(i)->price << " ";
    }
}

// returns size of the heap
int maxHeap::size()
{
    return heap.size();
}

