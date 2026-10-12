#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <vector>
#include <string>

extern int recurDepth;
extern int maxRecurDepth;

int partition(std::vector<std::string>& a, int lo, int hi);
void quicksort(std::vector<std::string>& a, int lo, int hi);
void qsort(std::vector<std::string>& a);

#endif
