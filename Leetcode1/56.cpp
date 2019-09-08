//
//  56.cpp
//  leetcode
//
//  Created by Xinran Han on 9/6/19.
//  Copyright © 2019 Xinran Han. All rights reserved.
//

#include <stdio.h>

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if(intervals.size()<2) return intervals;
    vector<vector<int>> result;
    vector<vector<int>> copy = intervals;
    
    sort(copy.begin(), copy.end());
    
    vector<int> temp = copy[0];
    for(int i = 1; i < copy.size(); i++){
        if(copy[i][0] > temp[1]){
            result.push_back(temp);
            temp = copy[i];
        }else if (copy[i][1] > temp[1]){
            temp = {temp[0], copy[i][1]};
        }else{
            temp = {temp[0], temp[1]};
        }
        
    }// for
    result.push_back(temp);
    
    return result;
}

int main(){
    
    vector<vector<int>> nums= {{1,4},{0,4}};
    vector<vector<int>> result =merge(nums);
    
    cout << result[0][0] << "," << result[0][1];
}
