/*
Problem:
Given an array arr[] of size n, find an equilibrium index (if any)
or return -1 if none exists. An equilibrium index has the sum of
elements at lower indexes equal to the sum at higher indexes.

Note: At start index, left sum is 0; at end index, right sum is 0.

Approach:
We can optimize space by using prefix and suffix sum variables
instead of arrays. We use the fact that:

PrefixSum(0 to pivot-1) + arr[pivot] + SuffixSum(pivot+1 to n-1) = Total

Therefore:
SuffixSum(pivot+1 to n-1) = Total - PrefixSum(0 to pivot-1) - arr[pivot]

The pivot is the index we're checking as a potential equilibrium point.
*/
#include <iostream>
#include <vector>
using namespace std;

int equilibriumPoint(vector<int> &arr)
{
    int prefSum = 0, total = 0;

    // Calculate the array sum
    for (int ele : arr)
    {
        total += ele;
    }

    // Iterate pivot over all the elements of the array and
    // till left != right
    for (int pivot = 0; pivot < arr.size(); pivot++)
    {
        int suffSum = total - prefSum - arr[pivot];
        if (prefSum == suffSum)
        {
            return pivot;
        }
        prefSum += arr[pivot];
    }

    // there is no equilibrium point
    return -1;
}

