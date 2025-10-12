#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size(), i = 0, j = 1;
        while (i < n && j < n)
        {
            while(i < n && nums[i] % 2 == 0) i += 2;
            while(j < n && nums[j] % 2) j += 2;
            if(i < n && j < n) swap(nums[i], nums[j]);
        }
        sort(nums.begin(), nums.end());
        return nums;
    }
};