/*
Problem: Segregate 0s and 1s in array

- Given an array with random 0s and 1s
- Goal: Put 0s on left, 1s on right
- Constraint: Single traversal only

Algorithm:
1. Use two pointers:
    - lo = 0 (start of array)
    - hi = length-1 (end of array)
2. Move lo right until finding a 1
3. Move hi left until finding a 0
4. Swap elements at lo and hi
5. Repeat until pointers meet
*/
#include <iostream>
#include <vector>
using namespace std;

// Function to put all 0s on the left and 
// all 1s on the right
void segregate0and1(vector<int>& arr) {
    int lo = 0;
    int hi = arr.size() - 1;

    while (lo < hi) {
      
        // If we have a 1 at lo
        if (arr[lo] == 1) {
          
            // And a 0 at hi
            if (arr[hi] != 1) {
                swap(arr[lo], arr[hi]);
                lo++;
                hi--;
            }
            else {          
                hi--;
            }  
        } else {
            lo++;
        }
    }
}
