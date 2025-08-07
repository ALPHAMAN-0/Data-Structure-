/*
Problem: Find the intersection of two arrays.
Intersection elements are common in both arrays.
The result should not have duplicates.

Approach:
1. Use unordered_set to store first array elements
2. Iterate through second array
3. If element exists in set, add to result
4. Remove from set to avoid duplicates
5. Time complexity: O(n+m), Space: O(n)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_set>
using namespace std;

vector<int>CommonValue(vector<int> &arr1,vector<int> &arr2){
   unordered_set<int> s(arr1.begin(), arr1.end());
   vector<int> result;

   for(auto i : arr2){
       if(s.find(i) != s.end()){
           result.push_back(i);
           s.erase(i);
       }
   }
   return result;
}
