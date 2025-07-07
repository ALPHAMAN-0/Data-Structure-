/*
PROBLEM: Find the repeating element in an array of size n
containing numbers from 1 to n-1, with one number repeating.

APPROACHES:

1) HashSet Method
    - Track visited elements in a HashSet
    - When we see an element twice, we found our duplicate

2) Visited Array Method
    - Use boolean array to mark visited elements
    - If element already visited, it's our duplicate

3) Sum Method
    - Sum of 1 to n-1 = (n-1)*n/2
    - Array sum - expected sum = duplicate

4) XOR Method
    - XOR all array elements with numbers 1 to n-1
    - All non-duplicates cancel out (x^x=0)
    - Result is our duplicate

5) Negative Marking
    - Mark visited indexes by making arr[arr[i]] negative
    - If already negative, arr[i] is the duplicate

6) Floyd's Cycle Detection
    - Treat array as linked list where arr[i] is next index
    - Use slow/fast pointers to find cycle
    - Entry point of cycle is the duplicate
*/
#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>


using namespace std;
// Approach 1
int findDuplicate(vector<int>& arr) {

    // Create an unordered_set
    unordered_set<int> s;
    for (int x : arr) {

        // If the element is already in the set
        if (s.find(x) != s.end())
            return x;
        s.insert(x);
    }
    return -1;
}
// Approach 2
int findDuplicate(vector<int>& arr) {
    int n = arr.size();
  
    // If any element is visited again, then
    // it is the repeating element
    vector<bool> visited(n + 1, 0); 
    
    for (int i = 0; i < n; i++) {
        if (visited[arr[i]])
            return arr[i];
        visited[arr[i]] = true;
    }

    return -1; 
}
// Approach 3
int findDuplicate(vector<int>& arr) {
    int n = arr.size();
  
    // Find the sum of elements in the array
    // and subtract the sum of the first n-1 
    // natural numbers to find the repeating element.
    int sum = accumulate(arr.begin(), arr.end(), 0);
    int duplicate = sum - ((n - 1) * n / 2);
    return duplicate;
}
//approach 4
int findDuplicate(vector<int>& arr) {
    int n = arr.size();
    int res = 0;

    // XOR all numbers from 1 to n-1 and 
    // elements in the array
    for (int i = 0; i < n - 1; i++) {
        res = res ^ (i + 1) ^ arr[i];
    }
    
    // XOR the last element in the array
    res = res ^ arr[n - 1];
    
    return res;
}
int findDuplicate(vector<int>& arr) {

    for (int i = 0; i < arr.size(); i++) {
        if (arr[abs(arr[i])] < 0) {
            return abs(arr[i]);
        }
        arr[abs(arr[i])] = -arr[abs(arr[i])];
    }

    return -1;
}
int findDuplicate(vector<int>& arr) {

    // slow pointer
    int slow = arr[0]; 

    // fast pointer
    int fast = arr[0]; 

    do {

        // moves one step
        slow = arr[slow];  

        // moves two steps
        fast = arr[arr[fast]];     
    } while (slow != fast);

    // reinitialize fast to the start
    fast = arr[0]; 
  
    // Loop until both pointers meet at the duplicate
    while (slow != fast) {
        slow = arr[slow];
        fast = arr[fast];
    }
  
   // Return duplicate number
    return slow;
}
