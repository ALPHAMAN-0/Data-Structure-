#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class removeMinimumCommonElements{
    public:
    int removeCommonElements(vector<int> arr0, vector<int> arr1){
        unordered_map<int,int> countElement;
        for(int x : arr0){
            countElement[x]++;
        }
        int removedCount = 0;

        for(int x : arr1){
            if(countElement.find(x)!=countElement.end() && countElement[x]>0){
                countElement[x]--;
                removedCount++;
            }
        }
        return removedCount;
    }
};
