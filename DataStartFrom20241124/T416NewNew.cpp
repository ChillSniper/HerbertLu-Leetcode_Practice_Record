#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

#define Test

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sz = nums.size(), sum = 0;
        for(int i = 0;i < sz;i ++)
            sum += nums[i];
        
        if(sum % 2)
            return false;
        int target = sum / 2;
        // f[i][j]
        vector<vector<int>> f(sz + 1, vector<int>(target + 1, 0));
        for(int i = 0;i <= sz;i ++)
            f[i][0] = 1;
        // f[i][s] = f[i - 1][s] || f[i - 1][s - x]
        int s = 0;
        for(int i = 1;i <= sz;i ++){
            int x = nums[i - 1];
            s += x;
            for(int j = min(s, target);j >= 0;j --){
                f[i][j] = f[i - 1][j];
                if(j - x >= 0)
                    f[i][j] |= f[i - 1][j - x];
            }
        }
        return f[sz][target];
    }
};