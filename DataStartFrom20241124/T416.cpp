#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int s = 0, sz = nums.size(), sum = 0;
        for(int i = 0;i < sz;i ++)
            s += nums[i];
        vector<int> f(s + 1, 0);
        for(int i = 1;i <= sz;i ++){
            int x = nums[i - 1];
            sum += x;
            for(int j = min(sum, s);j >= x;j --)
                f[j] = f[j] || f[j - x];
        }
        return f[s / 2];
    }
};