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
    std::vector<std::string> vec = populateVector(5000);
    reverseSort(vec);
    selection_sort(vec);

    reverseSort(vec);
    insert_sort(vec);

    mergeSort(vec);

    qsort(vec);
    std::cout << maxRecurDepth;

}
