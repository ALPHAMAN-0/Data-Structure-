/*
    Problem : Given two sorted arrays, the task
    is to merge them in a sorted manner.
    
    Approach : The idea is to use Merge function
    of Merge sort.

    Steps:
    1. Create an array arr3[] of size n1 + n2.
    2. Simultaneously traverse arr1[] and arr2[].
    3. Pick smaller of current elements in arr1[]
         and arr2[], copy this smaller element to
         next position in arr3[] and move ahead in
         arr3[] and the array whose element is picked.
    4. If there are remaining elements in arr1[] or
         arr2[], copy them also in arr3[].
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
vector<int> mearge(vector<int> &arr1,vector<int> &arr2){
    int i=0,j=0,k=0;
    int n1=arr1.size();
    int n2=arr2.size();

    vector<int> arr3(n1+n2);

    while(i<n1 && j<n2){
        if(arr1[i]<arr2[j]){
            arr3[k++] = arr1[i++];
        }
        else {
            arr3[k++] = arr2[j++];
        }
    }
    while(i<n1){
        arr3[k++] = arr1[i++];
    }
    while(j<n2){
        arr3[k++] = arr2[j++];
    }
    return arr3;
}
