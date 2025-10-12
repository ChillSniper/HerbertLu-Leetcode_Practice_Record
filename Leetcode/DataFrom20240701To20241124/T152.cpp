#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int f, g, MulMax;
        f = g = MulMax = nums[0];
        for(int i = 1;i < nums.size();i ++){
            int R1 = f * nums[i], R2 = g * nums[i];
            f = max(max(nums[i], R1), R2);
            g = min(min(nums[i], R1), R2);
            if(f >= MulMax) MulMax = f;
        }
        return MulMax;
    }
};