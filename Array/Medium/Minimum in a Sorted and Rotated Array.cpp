/*
Problem:
Given a sorted array of distinct elements arr[] of size n 
that is rotated at some unknown point, find the minimum element.

Approach (Binary Search):
- Find mid element and decide which half to search
- If arr[mid] > arr[high]: Search in right half (low = mid + 1)
- If arr[mid] <= arr[high]: Search in left half (high = mid)

Termination:
- When arr[low] < arr[high]: Array section is sorted
- Return arr[low] as the minimum element
*/
#include <iostream>
#include <vector>
using namespace std;

int findMin(vector<int> &arr) {
    int lo = 0, hi = arr.size() - 1;

    while (lo < hi) {
      
        // The current subarray is already sorted, 
        // the minimum is at the low index
        if (arr[lo] < arr[hi])        
            return arr[lo];
           
        // We reach here when we have at least
        // two elements and the current subarray
        // is rotated
      
        int mid = (lo + hi) / 2;

        // The right half is not sorted. So 
        // the minimum element must be in the
        // right half.
        if (arr[mid] > arr[hi])
            lo = mid + 1;
      
        // The right half is sorted. Note that in 
        // this case, we do not change high to mid - 1
        // but keep it to mid. As the mid element
        // itself can be the smallest
        else
            hi = mid;
    }

    return arr[lo]; 
}
