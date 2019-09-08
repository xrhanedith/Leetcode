//
//  48.cpp
//  leetcode
//
//  Created by Xinran Han on 9/6/19.
//  Copyright © 2019 Xinran Han. All rights reserved.
//
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

void rotate(vector<vector<int>>& matrix) {
    
    void rotate(vector<vector<int>>& matrix) {
        
        int size = matrix.size();
        if(size<2) return;
        
        for(int k = 0; k < size/2; ++k){
            for (int i = k; i < size-k-1; ++i){
                int temp = matrix[k][i];
                
                // 1 = 4
                matrix[k][i] = matrix[size-i-1][k];
                // 4 =3
                matrix[size-i-1][k] = matrix[size-k-1][size-i-1];
                // 3 = 2
                matrix[size-k-1][size-i-1] = matrix[i][size-k-1];
                // 2 = 1
                matrix[i][size-k-1] = temp;
            }
        }
        return;
    }

int main() {
    
}
