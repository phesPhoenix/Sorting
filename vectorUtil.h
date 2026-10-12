#ifndef VECTORUTIL_H
#define VECTORUTIL_H

#include <vector>
#include <string>
#include <random>

extern long long count;
extern std::mt19937 rng;

std::vector<std::string> insertCharToVec(std::vector<std::string>& a);
void reverseSort(std::vector<std::string>& a);
std::vector<std::string> randomizeVector(std::vector<std::string>& arr);
bool validateInput (std::vector<std::string>& a);
std::vector<std::string> populateVector(int n);
void printVector(std::vector<std::string>& arr);

#endif
