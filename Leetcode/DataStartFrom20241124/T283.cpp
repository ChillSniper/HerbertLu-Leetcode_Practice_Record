#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int sz = nums.size();
        int fs = 0, sl = 0;
        for(;fs < sz && sl < sz;){
            if(nums[fs]) nums[sl ++] = nums[fs ++];
            else fs ++;
        }   
        for(;sl < sz;sl ++) nums[sl] = 0;
    }
};