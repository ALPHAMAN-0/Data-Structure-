/*
    Problem:
    Sort an unsorted array into a wave form where:
    arr[0] >= arr[1] <= arr[2] >= arr[3] <= arr[4] >= ...

    Approach:
    We can achieve this by focusing only on even-positioned elements.
    If we ensure every even-positioned element is greater than its
    adjacent odd elements, the wave pattern will be formed automatically.

    Algorithm:
    1. Traverse even positions (0, 2, 4, ...)
    2. For each even position:
       - If current < previous: swap them
       - If current < next: swap them
*/
#include<iostream>
using namespace std;

void SortInWave(int arr[],int n){
    for(int i=0;i<n;i+=2){
        if(i>0 && arr[i]<arr[i-1]){
            swap(arr[i],arr[i-1]);
        }
        if(i<n-1 && arr[i]<arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
 
    }
}
int main(){
    int arr[] = {1, 3, 4, 2, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    SortInWave(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
