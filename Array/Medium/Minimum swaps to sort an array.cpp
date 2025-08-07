/*
Approach 1: Hash Map & Temporary Array
- Create a hash map to store array elements with their indices
- Make a temp array with sorted elements
- For each position, if current element is not correct:
    - Find where the correct element is (using hash map)
    - Swap them and update hash map
    - Count the swap

Approach 2: Cycle Detection
- Hash elements with their original positions
- Sort the array
- For each element not visited or in correct position:
    - Follow the cycle until returning to start
    - Count cycle size
    - Number of swaps needed = cycle size - 1
- Sum up swaps from all cycles
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
int minSwaps(vector<int> &arr) {
    
    // Temporary array to store elements in sorted order
    vector<int> temp(arr.begin(), arr.end());
    sort(temp.begin(), temp.end());
    
  	// Hashing elements with their correct positions
  	unordered_map<int, int> pos; 
    for(int i = 0; i < arr.size(); i++)
        pos[arr[i]] = i;
    
  	int swaps = 0;
    for(int i = 0; i < arr.size(); i++) {
        if(temp[i] != arr[i]) {
            
            // Index of the element that should be at index i.
            int ind = pos[temp[i]];
            swap(arr[i], arr[ind]);
            
            // Update the indices in the hashmap
            pos[arr[i]] = i; 
            pos[arr[ind]] = ind;
            
            swaps++; 
        }
    }
    return swaps; 
}
int minSwaps(vector<int> &arr) {
  	int n = arr.size();
    
    // Array to Keep track of those elements 
    // who already been included in the cycle
    vector<bool> vis(n, false);
  
  	// Hashing elements with their original positions
  	unordered_map<int, int> pos;
    for (int i = 0; i < n; i++)
        pos[arr[i]] = i;

    sort(arr.begin(), arr.end());

    int swaps = 0;
    for (int i = 0; i < n; i++) {

        // Already a part of another cycle Or
      	// in its correct position
        if (vis[i] || pos[arr[i]] == i)
            continue;

        int j = i, cycleSize = 0;
      
      	// We make a cycle until it comes
      	// back to first element again.
        while (!vis[j]) {
            vis[j] = true;

            // move to next element of the cycle
            j = pos[arr[j]];
            cycleSize++;
        }

        // Update answer by adding current cycle.
        if (cycleSize > 0) {
            swaps += (cycleSize - 1);
        }
    }
    return swaps;
}
