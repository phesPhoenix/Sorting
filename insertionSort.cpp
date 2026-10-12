#include "insertionSort.h"
#include "vectorUtil.h"
#include <iostream>
#include <chrono>
#include <utility>

void insert_sort(std::vector<std::string>& arr){
    std::cout << "Insertion Sort" << "\n";
    auto start = std::chrono::steady_clock::now();
    count = 0;
    int length = size(arr);
    for (int i = 1; i < length; i++)
    {
        for (int j = i; j >= 1; j--)
        {
            count++;
            if (arr[j] < arr[j-1]){
                std::swap(arr[j], arr[j-1]);
            } 
            else break;
        }
    }
    auto end = std::chrono::steady_clock::now(); 
    std::cout << "Comparisons: " << count << "\n";
    std::cout << "Time: " << (end - start).count() << " Nanoseconds" << "\n";

}
