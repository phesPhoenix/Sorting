#ifndef MERGESORT_H
#define MERGESORT_H

#include <vector>
#include <string>

void merge(std::vector<std::string>& a, std::vector<std::string>& aux, int lo, int mid, int hi);
void mSort(std::vector<std::string>& a, std::vector<std::string>& aux, int lo, int hi);
void mergeSort (std::vector<std::string>& arr);

#endif
