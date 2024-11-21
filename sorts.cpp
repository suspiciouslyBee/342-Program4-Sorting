//Stub header for sorting algorithm implementation  

#include <vector>

#include "sorts.h"

void MergeSort(std::vector<int> &item_vector, int start, int end) {
  static std::vector<int> temp_vector(item_vector.size()); 
  if (start < end) {
    int mid = start + (end - start) / 2; // Index of midpoint

    // Sort left half item_vector[first..mid]
    MergeSort(item_vector, start, mid);
    // Sort right half item_vector[mid+1..last]
    MergeSort(item_vector, mid + 1, end);
    // Merge the two halves
    Merge(item_vector, temp_vector, start, mid, end);
  } // end if
}

void Merge(std::vector<int> &item_vector,
  std::vector<int> &temp_vector, int first, int mid, int last)
{
  

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
  std::vector<int> temp_vector(item_vector.size());

  //divide down left

}



void BubbleSort(std::vector<int> &item_vector, int start, int end) {

  if(start >= end || item_vector.size() < 2) { return; }

  bool bubbleLatch = true;
  int maxIndex = end - 1;
	while (bubbleLatch == true) {
		bubbleLatch = false;
		for (int arrayIndex = start; arrayIndex <= maxIndex; arrayIndex++) {

			if (item_vector[arrayIndex] > item_vector[arrayIndex + 1]) {

        std::swap(item_vector[arrayIndex], item_vector[arrayIndex + 1]);
				bubbleLatch = true; //since a swap is made, keep latch active
			}
		}
	}

}

//TODO: need to incorporate start into the funct
void InsertionSort(std::vector<int> &item_vector, int start, int end) {
  for(int unsorted = start; unsorted < end; unsorted++) {

    int nextItem = item_vector[unsorted];

    int loc = unsorted;
    while ((loc > 0) && (item_vector[loc - 1] > nextItem)) {

      item_vector[loc] = item_vector[loc - 1];
    }

    item_vector[loc] = nextItem;
    loc--;

  }

}

void QuickSort(std::vector<int> &itemVector, int first, int last) {
  if(last - first < 4) {
    InsertionSort(itemVector, first, last);
    return;
  }


  int mid = (first + last) / 2;
  if (itemVector[first] > itemVector[last]) {
    std::swap(itemVector[first], itemVector[last]);
  }

  if (itemVector[first] > itemVector[mid]) {
    std::swap(itemVector[first], itemVector[mid]);
  } else if (itemVector[mid] > itemVector[last])  {
    std::swap(itemVector[mid], itemVector[last]);
  }

  int pivot = itemVector[mid];
  std::swap(itemVector[mid], itemVector[last - 1]);
  int left = first + 1;
  int right = last - 2;
  bool done = false;

  while (!done) {

    while (itemVector[left] < pivot) {
      left++;
    }

    while (itemVector[right] > pivot) {
      right--;
    }

    if (right > left) {
      std::swap(itemVector[left], itemVector[right]);
      right--;
      left++;
    } else {
      done = true;
    }
  }

  std::swap(itemVector[left], itemVector[last - 1]);
  QuickSort(itemVector, first, left - 1);
  QuickSort(itemVector, left + 1, last);
}


//Need to adapt to first
void ShellSort(std::vector<int> &arr, int first, int last) {

  //calc size
  int size = last - first;

  //gap starts

  for (int gap = size / 2; gap > 0; gap = (gap == 2) ? 1 : int(gap / 2.2)) {
    for (int i = first + gap; i < last; i++) {
      int tmp = arr[i];
      int j = i;
    for ( ; (j >= gap) && (tmp < arr[j - gap]); j -= gap) {
      arr[j] = arr[j - gap];
    }

    arr[j] = tmp;
    }
  }
}


