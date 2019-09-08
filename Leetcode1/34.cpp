//
//  main.cpp
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

vector<int> searchRange(vector<int>& nums, int target) {
    int size = nums.size();
    vector<int> result = {-1, -1};
    
    if (size==0) return result;
    if (size == 1){
        if (nums[0] == target) result = {0,0};
        return result;
    }
    if (size==2){
        if(nums[0]==target){
            if (nums[1]==target) result = {0,1};
            else result = {0,0};
        }else{
            if (nums[1]==target) result = {1,1};
            else result = {-1,-1};
        }
        return result;
    }
    
    int start = 0;
    int end = size - 1;
    int mid = (end + start) / 2;
    int found = -1;
    int low = -1;
    int high = -1;
    while(found==-1 || (low==-1||high==-1) ){
        if (nums[mid] < target){
            if (start==mid){
                if (nums[mid+1]==target){
                    low = mid+1;
                    high = mid+1;
                    found = 1;
                }
                break;
            }
            start = mid;
        }
        else if (nums[mid] > target){
            if (end==mid) break;
            end = mid;
        }
        else{
            found = mid;
            if (mid==0) {low = mid;}
            else if (nums[mid-1] < target){
                low = mid;
            }else{
                end = mid;
            }
            if (mid==size-1){high = mid;}
            else if(mid==size-2 && nums[mid+1] == target) high = mid+1;
            else if (nums[mid+1] > target){
                high = mid;
            }else{
                start = mid;
            }
        }
//        if(start==end-1) break;
        mid = (end + start) / 2;
    }
    if(found == -1) return result;
    
    result = {low, high};
    return result;
    
}

int main() {
    vector<int> nums= {1,2,3,3,3,3,4,5,9};
    int target = 3;
    vector<int> result =searchRange(nums, target);
    cout << result[0] << "," << result [1];
    
}
