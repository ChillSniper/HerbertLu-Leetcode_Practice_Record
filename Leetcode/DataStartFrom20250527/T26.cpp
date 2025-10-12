#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 1, j = 1;
        int sz = nums.size();
        for(;i < sz && j < sz;){
            if(nums[j] != nums[j - 1]){
                nums[i ++] = nums[j ++];
            }
            else{
                j ++;
            }
        }   
        return i;
    }
};
