/*
PROBLEM:
Given an integer array arr[] and an integer k, determine if there
are two indices i and j such that:
- arr[i] == arr[j] (same element values)
- |i - j| ≤ k (indices are at most k positions apart)
Return 'Yes' if such a pair exists, otherwise 'No'.

SOLUTION:
We'll use a HashSet to efficiently check for duplicates within
the k-distance window:

Algorithm:
1. Create an empty HashSet
2. Traverse array from left to right (i = 0 to n-1)
3. For each element arr[i]:
    - If arr[i] is already in the HashSet → return "Yes"
    - Otherwise, add arr[i] to the HashSet
    - If i ≥ k, remove arr[i-k] from HashSet (sliding window)
4. If no duplicates found, return "No"

Time Complexity: O(n)
Space Complexity: O(min(n, k))
*/

#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

bool checkDuplicatesWithinK(vector<int> &arr, int k) {
    // Creates an empty hashset
    unordered_set<int> s;

    // Traverse the input array
    for (int i = 0; i < arr.size(); i++) {
      
        // If already present in hash, then we found
        // a duplicate within k distance
        if (s.find(arr[i]) != s.end())
            return true;

        // Add this item to hashset
        s.insert(arr[i]);

        // Remove the k+1 distant item
        if (i >= k)
            s.erase(arr[i - k]);
    }
    return false;
}
int main(){
    vector<int> arr = {10, 5, 3, 4, 3, 5, 6};
    int k = 3;
    if(checkDuplicatesWithinK(arr, k)){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}
