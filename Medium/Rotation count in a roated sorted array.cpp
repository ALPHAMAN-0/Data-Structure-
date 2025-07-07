/*
PROBLEM:
Given an array arr[] with distinct numbers sorted in increasing order that has 
been right rotated k times, find the value of k.

APPROACH:
This problem is a variation of finding the smallest element in the array. 
We need to find the index of the minimum element instead of the value.

BINARY SEARCH SOLUTION:
We find the mid element and decide which half to search next:

- If arr[mid] > arr[high]:
    The smallest element is in the right half
    So we set low = mid + 1

- If arr[mid] <= arr[high]:
    The smallest element is in the left half
    So we set high = mid

TERMINATION CONDITION:
When arr[low] <= arr[high], the current subarray is sorted
We return arr[low] as our answer

This approach efficiently finds the rotation count without explicitly
checking the whole sorted array.
*/
#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
int findMin(vector<int> &arr)
{
    int low = 0, high = arr.size() - 1;

    while (low < high)
    {
        // The current subarray is already sorted, 
        // the minimum is at the low index
        if (arr[low] <= arr[high])        
            return low;
           
        // We reach here when we have at least
        // two elements and the current subarray
        // is rotated
      
        int mid = (low + high) / 2;

        // The right half is not sorted. So 
        // the minimum element must be in the
        // right half.
        if (arr[mid] > arr[high])
            low = mid + 1;
      
        // The right half is sorted. Note that in 
        // this case, we do not change high to mid - 1
        // but keep it to mid. Ad the mid element
        // etself can be the smallest
        else
            high = mid;
    }

    return low; 
}
