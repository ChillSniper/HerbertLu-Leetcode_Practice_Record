#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <limits.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int sz = nums.size(), s = 0;
        vector<int> f(target + 1, 0);
        f[0] = 0;
        for(int i = 1;i <= sz;i ++){
            int l = nums[i - 1];
            s += l;
            for(int j = min(s, target);j >= l;j --){
                f[j] = max(f[j], f[j - l] + 1);
            }
        }
        return f[target];
    }
};

// 注意，代码还是存在漏洞 问题出在哪呢
// 递推方程为 f[i][j] = max(f[i - 1][j], f[i - 1][j - len] + 1);
// 首先要考虑到二维时逆序
// 目前的问题在于，f[]初始化为0时，会产生错误
// 好吧，我找到问题出在哪了。可能最终数值达不到target。但是由于二层循环从target开始，可能会误触
// 这个非常坑，初始化的时候务必初始化成INT_MIN，不然会造成由于区间的连续，导致值的错误传递！