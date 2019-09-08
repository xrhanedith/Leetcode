//
//  134.cpp
//  Leetcode1
//
//  Created by Xinran Han on 9/8/19.
//  Copyright © 2019 Xinran Han. All rights reserved.
//

#include "134.hpp"

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;


int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int size = gas.size();
    
    //double the vector to simplfy circular question
    gas.insert(gas.end(),gas.begin(), gas.end());
    cost.insert(cost.end(),cost.begin(), cost.end());
    
    for (int i = 0; i < size; ++i){
        int tank = 0;
        //find start pt
        if (gas[i]>=cost[i]){
            tank = gas[i];
            //loop until reach same station
            for(int j=i; j < size+i; ++j){
                tank -= cost[j];
                //check if tank empty
                if(tank<0) break;
                tank += gas[j+1];
                if(j==i+size-1) return i;
            }
        }
    }
    return -1;
    }

int main(){
    vector<int> gas = {1,2,3,4,5};
    vector<int> cost = {3,4,5,1,2};
    int result = canCompleteCircuit(gas, cost);
    std::cout << result;
}
