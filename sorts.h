#ifndef SORTS_H_
#define SORTS_H_

#include <vector>

void BubbleSort(std::vector<int> &item_vector, int start, int end);
void InsertionSort(std::vector<int> &item_vector, int start, int end);
void QuickSort(std::vector<int> &itemVector, int first, int last);
void ShellSort(std::vector<int> &arr, int first, int last);

void IterativeMergeSort(std::vector<int> &item_vector, int start, int end);
void Merge(std::vector<int> &item_vector,
            std::vector<int> &temp_vector, int first, int mid, int last);
void MergeSort(std::vector<int> &item_vector, int start, int end);

#endif //SORTS_H_