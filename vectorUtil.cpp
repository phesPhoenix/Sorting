#include "vectorUtil.h"
#include <iostream>
#include <random>
#include <algorithm>
#include <cstdlib>
#include<utility>
#include <fstream>
long long count = 0; //lets other files read count
std::mt19937 rng(12345);


std::vector<std::string> insertCharToVec(std::vector<std::string>& a)
{
    std::fstream file ("ammendmends.txt");
    std::string line;
    while (std::getline(file, line)){
        a.push_back(line);
    }

    return a;
    
}



void reverseSort(std::vector<std::string>& a){
    std::sort(a.begin(), a.end());
    std::reverse(a.begin(), a.end());
}
    

std::vector<std::string> randomizeVector(std::vector<std::string>& arr){
    std::shuffle(arr.begin(), arr.end(), rng);
    
    return arr;

}

bool validateInput (std::vector<std::string>& a){
    for (int i = 1; i < a.size(); i++){
        if (a[i-1] > a[i]) return false; 
    }
    std::cout << "RESULTS VALIDATED" << "\n";
    return true;
}

std::vector<std::string> populateVector(int n){
    std::vector<std::string> array(n);
    for(int i = 0; i < n; i++){
        array[i] = std::to_string(rand() % 99);
    }
    return array;
}

void printVector(std::vector<std::string>& arr){
    for (std::string i : arr){
        std::cout << i << " ";
    }
    std::cout << "\n";
}
