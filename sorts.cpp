//Stub header for sorting algorithm implementation  

#include <vector>

#include "sorts.h"

void MergeSort(std::vector<int> &item_vector, int start, int end) {
  if (start < end) {
    int mid = start + (end - start) / 2; // Index of midpoint

    // Sort left half item_vector[first..mid]
    MergeSort(item_vector, start, mid);
    // Sort right half item_vector[mid+1..last]
    MergeSort(item_vector, mid + 1, end);
    // Merge the two halves
    Merge(item_vector, start, mid, end);
  } // end if
}

void Merge(std::vector<int> &item_vector, int first, int mid, int last)
{
  std::vector<int> temp_vector; 

  int first1 = first;
  int last1 = mid;
  int first2 = mid + 1;
  int last2 = last;
  // End of second subarray
  // While both subarrays are not empty, copy the
  // smaller item into the temporary array
  int index = first1;
  // Next available location in temp_vector
  while ((first1 <= last1) && (first2 <= last2)) {
    
    // At this point, temp_vector[first..index-1] is in order
    if (item_vector[first1] <= item_vector[first2]) {
      temp_vector[index] = item_vector[first1];
      first1++;
    } else {
      temp_vector[index] = item_vector[first2];
      first2++;
    } // end if
    index++;
  }

  while (first1 <= last1) {
  // At this point, temp_vector[first..index-1] is in order
    temp_vector[index] = item_vector[first1];
    first1++;
    index++;
  } // end while
    // Finish off the second subarray, if necessary
  while (first2 <= last2) {
    // At this point, temp_vector[first..index-1] is in order
    temp_vector[index] = item_vector[first2];
    first2++;
    index++;
  } // end for

  // Copy the result back into the original array
  for (index = first; index <= last; index++) {
    item_vector[index] = temp_vector[index];
  }
// end merge
}

//This iterative sort progresses each stage linearly, essentially scanning.
//Sort, zipper.
//need to assume atleast two elements
//need to reimplement zipper merge from prog 3
void IterativeMergeSort(std::vector<int> &item_vector, int start, int end) {
  int windowSize = 1;
  int offset = 0;
  int hopper = 0;
  std::vector<int> temp_vector;
  std::vector<int>::iterator BStart, CStart, ;





  //swap
  for(int i = 0; i < windowSize; i++ ) {
    item_vector[offset + i]
  }

}