/*
Problem:
-------
Given an array of integers, move all zeros to the end of the array
while maintaining the relative order of non-zero elements.

Solution Approach:
---------------
1. Use a pointer (count) to track where the next non-zero element should go
2. When we find a non-zero element, swap it with the element at position 'count'
3. This automatically pushes zeros toward the end of the array
4. Increment 'count' after each swap

Note: In C++, we can also use the built-in stable_partition() function 
to achieve the same result more efficiently.
*/
// C++ Program to move all zeros to end using one traversal

#include <iostream>
#include <vector>
#include <algorithm> // for std::swap
#include <iterator> // for std::begin, std::end
#include <utility> // for std::swap
#include <numeric> // for std::accumulate
#include <functional> // for std::less
using namespace std;

// Function which pushes all zeros to end of array
void pushZerosToEnd(vector<int>& arr) {
  
    // Pointer to track the position for next non-zero element
    int count = 0;
     
    for (int i = 0; i < arr.size(); i++) {

        // If the current element is non-zero
        if (arr[i] != 0) {
          
            // Swap the current element with the 0 at index 'count'
            swap(arr[i], arr[count]);
            // Move 'count' pointer to the next position
            count++;
        }
    }
}
void pushZerosToEnd(vector<int> &arr) {
    stable_partition(arr.begin(), arr.end(), [](int n) { 
                                       return n != 0; });
}
int main() {
    vector<int> arr = {1, 2, 0, 4, 3, 0, 5, 0};
    pushZerosToEnd(arr);
    for (int num : arr) {
        cout << num << " ";
    }
    return 0;
}
