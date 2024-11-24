//Stub header for sorting algorithm implementation  

#include <vector>

#include "sorts.h"

// Implemented with the textbook example
void MergeSort(std::vector<int> &item_vector, int start, int end) {
  
  if(start < 0 || end < 0) { return; }

  
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

// Implemented with the textbook example
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
//
//Disclaimer:
//In the interest of time, and by the permission granted in the 11/18 class at 
//time stamp 1:12:55: This function is loosely adapted from Wikipedia's example
//and the implementation steps outlined in the same class.

void IterativeMergeSort(std::vector<int> &item_vector, int start, int end) {
  static std::vector<int> temp_vector(item_vector.size());

  if(start < 0 || end < 0) { return; }

  int windowSize = 1;
  int actualSize = end - start;
  int index = start;
  int fakeMid = 0;
  int fakeLast = 0;


  //garuntee's atleast one loop has a full valid thing
  while(windowSize < actualSize) {
    //iterate through the list, sorting groups of sublists
    while(index < end) {
      
      fakeMid = index + windowSize - 1;
      if(fakeMid > end) {
        fakeMid = end;
      }

      fakeLast = index + (windowSize * 2) - 1;
      if(fakeLast > end) {
        fakeLast = end;
      }


      Merge(item_vector, temp_vector, index, fakeMid, fakeLast);

      index += (windowSize * 2);
    }
  index = start;
  windowSize *= 2;
  

}


}




void BubbleSort(std::vector<int> &item_vector, int start, int end) {

  if(start >= end || item_vector.size() < 2) { return; }


  // Repeatedly passes the array, swapping each out of order element until 
  // no more swaps are required
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

void InsertionSort(std::vector<int> &item_vector, int start, int end) {

  if(start < 0 || end < 0) { return; }
  if(start >= end || item_vector.size() < 2) { return; }


  // Grabs the element, drag it to the right place
  // Essentially creating a sorted sublist in the main list, and then inserting
  // the first element of the unsorted sublist and adding it to the sorted
  // sublist
  for(int unsorted = start; unsorted <= end; unsorted++) {

    int nextItem = item_vector[unsorted];

    int loc = unsorted;
    while ((loc > 0) && (item_vector[loc - 1] > nextItem)) {

      item_vector[loc] = item_vector[loc - 1];
      loc--;
    }

    item_vector[loc] = nextItem;


  }

}

void QuickSort(std::vector<int> &itemVector, int first, int last) {

  
  if(first< 0 || last < 0) { return; }
  if(first >= last || itemVector.size() < 2) { return; }

  if(last - first < 4) {
    InsertionSort(itemVector, first, last);
    return;
  }

  // Gets midpoint setup so that can be the midpoint
  int mid = (first + last) / 2;
  if (itemVector[first] > itemVector[last]) {
    std::swap(itemVector[first], itemVector[last]);
  }

  if (itemVector[first] > itemVector[mid]) {
    std::swap(itemVector[first], itemVector[mid]);
  }
  if (itemVector[mid] > itemVector[last])  {
    std::swap(itemVector[mid], itemVector[last]);
  }

  // Sets up pivot, then tosses smaller items to before, larger items to after
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

  // Recursively divide the array. and use QS on that sub array
  std::swap(itemVector[left], itemVector[last - 1]);
  QuickSort(itemVector, first, left - 1);
  QuickSort(itemVector, left + 1, last);
}


//Need to adapt to first
void ShellSort(std::vector<int> &arr, int first, int last) {\

  if(first < 0 || last < 0) { return; }
  if(first >= last || arr.size() < 2) { return; }

  //calc size
  int size = last - first;
  int tmp = 0;
  int j = 0;

  //gap starts

  for (int gap = size / 2; gap > 0; gap = (gap == 2) ? 1 : int(gap / 2.2)) {
    for (int i = first + gap; i < last + 1; i++) {
      tmp = arr[i];
      j = i;
    for ( ; (j >= gap) && (tmp < arr[j - gap]); j -= gap) {
      arr[j] = arr[j - gap];
    }

    arr[j] = tmp;
    }
  }
}


 