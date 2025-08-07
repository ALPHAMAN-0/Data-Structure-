/*
Problem:
Given an array of n integers, find 3 elements where a[i] < a[j] < a[k] 
and i < j < k in O(n) time. Print any one triplet if multiple exist.

Approach:
1. Find two elements arr[i] & arr[j] such that arr[i] < arr[j] and i < j.
   
2. Then find a third element arr[k] greater than arr[j].

3. This can be done in single pass:
   - Track min element (arr[i])
   - When we find an element > min, it becomes arr[j]
   - Continue searching for arr[k] > arr[j]
   
4. If we find lower values during iteration, update arr[i] and arr[j]
   to these lower values to increase chances of finding arr[k].
   
Example: {3, 4, -1, 0, 2}
- Initially: min = 3, arr[i] = 3, arr[j] = 4
- After finding -1: update min = -1, arr[i] = -1
- After finding 0: arr[j] = 0
- After finding 2: arr[k] = 2, thus triplet = {-1, 0, 2}
*/
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<int> find3Numbers(const vector<int>& arr) 
{
    // If number of elements < 3, no triplets are possible
    if (arr.size() < 3) {
        return {}; 
    }
  
    // track best sequence length (not current sequence length)
    int seq = 1;
  
    // min number in the array
    int min_num = arr[0];  
  
    // least max number in best sequence
    int max_seq = INT_MAX;
  
    // save arr[i]
    int store_min = min_num;
  
    // Iterate from 1 to arr.size()
    for (int i = 1; i < arr.size(); i++) 
    {
        if (arr[i] == min_num)
            continue;
        else if (arr[i] < min_num) 
        {
            min_num = arr[i];
            continue;
        } 
        
        // this condition is only hit
        // when current sequence size is 2
        else if (arr[i] < max_seq) {    
            max_seq = arr[i]; 
            store_min = min_num;
        } 
        
        // Increase best sequence length & 
        // save next number in triplet
        else if (arr[i] > max_seq) {
            return {store_min, max_seq, arr[i]}; 
        }
    }
  
    // No triplet found
    return {}; 
}
