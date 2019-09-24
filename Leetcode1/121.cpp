//
//  121.cpp
//  Leetcode1
//
//  Created by Xinran Han on 9/23/19.
//  Copyright © 2019 Xinran Han. All rights reserved.
//

#include <stdio.h>

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int maxPrice = 0;
        int maxProf = 0;
        for(int i = prices.size()-1; i >= 0; --i){
            if(prices[i] > maxPrice) maxPrice = prices[i];
            if(maxPrice - prices[i] > maxProf) maxProf = maxPrice - prices[i];
        }
        return maxProf;
    }
};
