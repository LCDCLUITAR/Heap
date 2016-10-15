#pragma once
#ifndef MINHEAP_H_

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <unistd.h>
#include <sstream>
#include <fstream>
#include <vector>
#include <iterator>
#define SLEEP sleep(1)
using namespace std;


// Class Declaration
class MinHeap{
    private:
        vector<int> heap;
        int leftistNode(int);
        int rightistNode(int);
        int parentNode(int);
        void heapifyUp(int);
        void heapifyDown(int);
    public:
        void insert(int);
		void deleteNode(int);
		int search(int);
		void change(int, int);
        void printPostOrder();
};
#endif