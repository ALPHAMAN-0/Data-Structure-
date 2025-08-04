/*
Problem: Given an array arr[], the task is to find the maximum distance between 
two occurrences of any element.
If no element occurs twice, return 0.

Approach: Use a hash map to store the first occurrence of each element and calculate the distance 
when the element is found again.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int maxDistance(vector<int> &arr) {
        // Code here
        unordered_map<int,int> hashSet;
        
        int result = 0;
        for(int i=0;i<arr.size();i++){
            if(hashSet.find(arr[i])==hashSet.end()){
                hashSet[arr[i]] = i;
            }
            else{
                result = max(result,i-hashSet[arr[i]]);
            }
        }
        return result;
    }
};
