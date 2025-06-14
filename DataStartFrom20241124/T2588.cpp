#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
#define Test

class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        // 这种题该从何入手呢 ？
        // 没有下手的任何思路
        // 题意是要统计目的子数组的个数
        // 这道题的思路就是 由于转换为了二进制，所以异或之后的总和为0
        // 那么问题就转换为 求当前异或值与此前异或值相等的值的总和
        // 当然，有一种很奇怪的情况 s[i] = s[i - 1] = x;
        // 这就意味着 x[i] = 0;
        // 当然这也可以加上去对吧....
        unordered_map<int, int> ump;
        ump[0] = 1;
        long long ans = 0;
        int sz = nums.size(), cur = 0;
        for(int i = 0;i < sz;i ++){
            cur = cur ^ nums[i];
            if(ump.count(cur))
                ans += ump[cur];
            ++ ump[cur];
        }
        return ans;
    }

};