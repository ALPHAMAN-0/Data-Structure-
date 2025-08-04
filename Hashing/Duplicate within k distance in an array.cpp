/*
Problem:
Given an integer array arr[] and an integer k, 
determine whether there exist two indices i and j 
such that arr[i] == arr[j] and |i - j| ≤ k. 
If such a pair exists, return 'Yes', otherwise return 'No'.

Approach:
- Use a HashSet to store elements of arr[].
- Check for any duplicate within k distance.
- Remove elements that are more than k distance from the current element.

Algorithm:
1. Create an empty HashSet.
2. Traverse all elements from left to right.
  Let the current element be arr[i].
3. If arr[i] is present in HashSet, return true.
4. Else, add arr[i] to HashSet.
  Remove arr[i-k] from HashSet if i >= k.
*/

#include<iostream>
#include<unordered_map>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
  public:
    bool checkDuplicatesWithinK(vector<int> arr,int k){
       unordered_set<int> hashSet;
       for(int i=0;i<arr.size();i++){
           if(hashSet.find(arr[i])!=hashSet.end()){
                return true;
           }
           hashSet.insert(arr[i]);
           if(i>= k){
               hashSet.erase(arr[i-k]);
           }
       }
       return false;
    }
};
