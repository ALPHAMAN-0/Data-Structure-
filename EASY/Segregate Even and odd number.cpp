/*
Problem: Segregate even and odd numbers in array
- Put all even numbers first, followed by odd numbers
- Two implementations provided: 
    1. Two-pointer approach (segregate)
    2. STL stable_partition (rearrangeEvenAndOdd)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
using namespace std;

// Function to segregate even and odd numbers
void segregate(vector<int>& arr) {
    int lo = 0, hi = arr.size() - 1;

    // Iterate while hi >= lo
    while (hi >= lo) {
      
        // Check if arr[lo] is odd
        if (arr[lo] % 2 != 0) {
            if (arr[hi] % 2 == 0) {
              
                // Swap arr[lo] and arr[hi]
                swap(arr[lo], arr[hi]);
                lo++;
                hi--;
            } else {
                hi--;
            }
        } else {
            lo++;
        }
    }
}
void rearrangeEvenAndOdd(vector<int>v)
{
    
    // Using stable partition with lambda expression
    stable_partition(v.begin(), v.end(),
                     [](auto a) { return a % 2 == 0; });

    for (int num : v)
        cout << num << " ";
}
