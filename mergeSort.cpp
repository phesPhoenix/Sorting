#include "mergeSort.h"
#include "vectorUtil.h"
#include <iostream>
#include <chrono>

void merge(std::vector<std::string>& a, std::vector<std::string>& aux, int lo, int mid, int hi){
    for (int k = lo; k <= hi; k++){
        aux[k] = a[k];
    }

    int i = lo, j = mid+1;
    for (int k = lo; k <= hi; k++)
    {
        if (i>mid)a[k] = aux[j++];
        else if(j > hi) a[k]=aux[i++];
        else if (aux[j] < aux[i]) {
            count++;
            a[k] = aux[j++];}
        else {count++; 
            a[k]=aux[i++];
        }
    }
}

void mSort(std::vector<std::string>& a, std::vector<std::string>& aux, int lo, int hi){
    if (hi <= lo) return;
    int mid = lo+(hi-lo) /2;
    mSort(a,aux,lo,mid);
    mSort(a,aux,mid+1, hi);
    merge(a,aux,lo,mid,hi);
}

void mergeSort (std::vector<std::string>& arr){
    auto start = std::chrono::steady_clock::now();
    count = 0;
    int N = arr.size();
    std::vector<std::string> aux(N);
    mSort(arr, aux, 0 , N-1);
    auto end = std::chrono::steady_clock::now(); 
    std::cout << "Merge Sort" << "\n";  
    std::cout << "Comparisons: " << count << "\n";
    std::cout << "Time: " << (end - start).count() << " Nanoseconds" << "\n";
}
