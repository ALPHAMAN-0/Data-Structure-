
/*
    Problem Statement:
    Given an array arr[] and a positive integer k, the task is to count all pairs (i, j) such that i < j and 
    absolute value of (arr[i] - arr[j]) is equal to k.

    Approach:
    - The solution uses a hash map (unordered_map) to efficiently count the number of pairs with absolute difference k.
    - For each element in the array, it checks if (arr[i] + k) or (arr[i] - k) exists in the hash map, 
      and adds the frequency of those elements to the pair counter.
    - The hash map stores the frequency of each element encountered so far, allowing O(1) lookups and updates.
    - This approach ensures an overall time complexity of O(n), where n is the size of the array.
*/
#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>

using namespace std;

class countPairs{
    public:
    int getPairsCount(vector<int> arr,int k){
        int n = arr.size();
        unordered_map<int,int> hashSet;
        int pairCounter=0;
        
        for(int i=0;i<n;i++){
            if(hashSet.find(arr[i]+k)!=hashSet.end()){
                pairCounter+=hashSet[arr[i]+k];
            }
            if(hashSet.find(arr[i]-k)!=hashSet.end()){
                pairCounter+=hashSet[arr[i]-k];
            }
            hashSet[arr[i]]++;
        }
        
        
        return pairCounter;
    }
};
