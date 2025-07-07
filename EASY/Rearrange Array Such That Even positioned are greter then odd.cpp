/*
Problem:
Rearrange an array so that:
- For even positions i: arr[i] >= arr[i-1]
- For odd positions i: arr[i] <= arr[i-1]
- Note: Using 1-based indexing (position 1 is the first element)

Approach:
We simply traverse the array from index 1 to n-1 and at each position:
- If current position is even: ensure current element >= previous element
- If current position is odd: ensure current element <= previous element
- If condition is not satisfied, swap the current element with the previous one
*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> rearrangeArray(vector<int> &arr) {
    int n = arr.size();

    vector<int> result(n);

    // Traverse the array and make adjustments to satisfy the condition
    for (int i = 1; i < n; i++) {

        // Check if the index is even (1-based), i.e., i+1 is even
        if ((i + 1) % 2 == 0) {
          
            // Ensure that the current element is greater than or
          // equal to the previous element
            if (arr[i] < arr[i - 1]) {
                swap(arr[i], arr[i - 1]);
            }
        }
        else {
            // Ensure that the current element is less than or equal
          // to the previous element
            if (arr[i] > arr[i - 1]) {
                swap(arr[i], arr[i - 1]);
            }
        }
    }

    result = arr;

    return result;
}
