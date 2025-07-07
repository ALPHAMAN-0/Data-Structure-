/*
Array Reversal

Problem: Reverse the elements of an array so that the first element becomes 
the last, the second becomes second-to-last, and so on.

Solution: Iterate through the first half of the array, swapping each element 
with its corresponding element from the end:
- Swap arr[0] with arr[n-1]
- Swap arr[1] with arr[n-2]
- And so on...

This can be implemented by swapping arr[i] with arr[n-i-1] for i from 0 
to n/2-1, where n is the array length.
*/
// C++ Program to reverse an array by swapping elements

#include <iostream>
#include <vector>
using namespace std;

// function to reverse an array
void reverseArray(vector<int> &arr) {
    int n = arr.size();
    
    // Iterate over the first half and for every index i,
    // swap arr[i] with arr[n - i - 1]
    for(int i = 0; i < n/2; i++) {
    	swap(arr[i], arr[n - i - 1]);
    }
}

int main() {
    vector<int> arr = { 1, 4, 3, 2, 6, 5 };

    reverseArray(arr);
  
    for(int i = 0; i < arr.size(); i++) 
        cout << arr[i] << " ";
    return 0;
}
