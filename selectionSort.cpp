#include "selectionSort.h"
#include "vectorUtil.h"
#include <iostream>
#include <chrono>
#include <utility>

void selection_sort(std::vector<std::string>& arr){
    std::cout << "Selection Sort" << "\n";
    count = 0;
    auto start = std::chrono::steady_clock::now();
    int min = 0;
    for (int i =0; i < arr.size(); i++){
        min = i;
        for (int j=i+1; j < arr.size(); j++){
            count++;
            if (arr[j] < arr[min])
                min = j;   
        }
        std::swap(arr[i],arr[min]);
    }
    auto end = std::chrono::steady_clock::now(); 
    std::cout << "Comparisons: " << count << "\n";
    std::cout << "Time: " << (end - start).count() << " Nanoseconds" << "\n";
}
