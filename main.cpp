#include <vector>
#include <iostream>
#include <string>
#include "vectorUtil.h"
#include "selectionSort.h"
#include "insertionSort.h"
#include "mergeSort.h"
#include "quickSort.h"


int main()
{
    std::vector<std::string> vec;
    insertTokensToVec(vec, 8000);
    qsort(vec);
    printVector(vec);
    validateInput(vec);




}
