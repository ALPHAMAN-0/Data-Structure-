#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class findPairWithGivenSum{
    public:
    vector<pair<int,int>> findPair(vector<vector<int>> matrix,int sum){
        unordered_map<int,int> elementMap;
        vector<pair<int,int>> result;

        for(int row=0;row<matrix.size();row++){
            for(int colum = 0; colum<matrix[row].size();colum++){
                int element = matrix[row][colum];
                int complement = sum - element;

                if(elementMap.find(complement)!=elementMap.end()){
                    result.push_back({element, complement});
                }
                elementMap[element] = row;
            }
        }
        return result;
    }
};
