/*
problem: Given an integer array of N elements. You need to find the maximum
sum of two elements such that sum is closest to zero. This problem is a
variation of standard 2 Sum problems.

Note: If we have two or more ways to form sum closest to zero, return the
maximum sum.

approach:
Sort the array, then use two pointer algorithm to find sum closest to zero.
We adjust pointers according to current sum - increment left pointer when
sum is negative and decrement right pointer otherwise.

Steps:
1. Sort the given array.
2. Initialize pointers i and j at beginning and end of sorted array.
3. Initialize variables sum = arr[i] + arr[j] and diff = abs(sum).
4. While i < j:
    - Calculate current sum as arr[i] + arr[j].
    - If sum equals zero, return 0 (closest possible).
    - If abs(current sum) < abs(diff), update diff and sum.
    - If abs(current sum) = abs(diff), set sum to max(sum, current sum).
    - If sum < 0 then i++ else j--.
5. Return final sum, which is max sum closest to zero.
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;
int closestToZero(vector<int>& arr) {
  
    // Sorting the vector in ascending order
    sort(arr.begin(), arr.end());

    int i = 0, j = arr.size() - 1;

    // Initializing sum with the first 
    // and last elements
    int sum = arr[i] + arr[j];

    // Initializing the result with 
    // the absolute value of the initial sum
    int diff = abs(sum);

    while (i < j) {
      
        // If we have zero sum, there's no 
        // result better. Hence, we return
        if (arr[i] + arr[j] == 0)
            return 0;

        // If we get a better result, we update the difference
        if (abs(arr[i] + arr[j]) < abs(diff)) {
            diff = abs(arr[i] + arr[j]);
            sum = arr[i] + arr[j];
        } else if (abs(arr[i] + arr[j]) == abs(diff)) {
          
            // If there are multiple pairs with the
            // same minimum absolute difference,
            // return the pair with the larger sum
            sum = max(sum, arr[i] + arr[j]);
        }

        // If the current sum is greater than
        // zero, we search for a smaller sum
        if (arr[i] + arr[j] > 0)
            j--;
      
        // Else, we search for a larger sum
        else
            i++;
    }
    return sum;
}
