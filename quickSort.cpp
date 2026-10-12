#include "quickSort.h"
#include "vectorUtil.h"
#include <iostream>
#include <chrono>
#include <utility>
int recurDepth = 0;
int maxRecurDepth = 0;

int partition(std::vector<std::string>& a, int lo, int hi){
    int i = lo, j = hi+1;
    while (true){
        while ( a[++i] < a[lo])
        {
            count++;
            if (i == hi) break;
        }
        count++;
        while ( a[--j] > a[lo]){
            count++;
            if (j==lo) break;
        }
        count++;
        if (i>=j) break;
        std::swap(a[i], a[j]);

    }

    std::swap(a[lo],a[j]);
    return j;
}


void quicksort(std::vector<std::string>& a, int lo, int hi){
    if (hi<= lo) return;
    recurDepth++;
    if (recurDepth > maxRecurDepth ) maxRecurDepth = recurDepth;
    int j = partition(a,lo,hi);
    quicksort(a,lo,j-1);
    quicksort(a,j+1, hi);
    recurDepth--;
}

void qsort(std::vector<std::string>& a)
{
    count = 0;
    int N = a.size();
    auto start = std::chrono::steady_clock::now();

    quicksort(a,0,N-1); 
    auto end = std::chrono::steady_clock::now(); 

    std::cout << "Quick Sort" << "\n";
    std::cout << "Comparisons: " << count << "\n";  
    std::cout << "Time: " << (end - start).count() << " Nanoseconds" << "\n";

}
