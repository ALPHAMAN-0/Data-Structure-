/*
Problem:
Given a sorted array arr[] (may contain duplicates) of size n 
that is rotated at some unknown point, find the maximum element.

Binary Search Approach:
- Find mid element and decide which half to search
- Use comparisons between elements to determine direction

Examples:
1. {4, 5, 6, 9, 10, 1, 2}
    - mid = (0 + 7) / 2 = 3, arr[3] = 9
    - If arr[mid] > arr[lo], go to right half
    - We set low = mid

2. {50, 10, 20, 30, 40}
    - mid = (0 + 4)/2 = 2, arr[2] = 20
    - If arr[mid] <= arr[lo], go to left half

Termination:
When arr[lo] <= arr[hi], the current subarray is sorted,
so return arr[hi]. This avoids checking if mid is smaller
than both adjacent elements.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findMax(vector<int> &arr)
{
    int lo = 0, hi = arr.size() - 1;

    while (lo < hi)
    {
        // If the current subarray is already sorted,
        // the maximum is at the hi index
        if (arr[lo] <= arr[hi])
            return arr[hi];
        
        int mid = (lo + hi) / 2;

        // The left half is sorted, the maximum must 
        // be either arr[mid] or in the right half.
        if (arr[mid] > arr[lo])
            lo = mid;
        else
            hi = mid - 1;
    }

    return arr[lo]; 
}
