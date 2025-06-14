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
    int lengthOfLIS(vector<int>& nums) {
        // 1, 5, 3, 2, 7, 5, 4, 2
        // 所以为什么要替换第一个比它大的数呢
        // 因为替换比它大的数能够使得后续的可能潜在最长序列更大
        // cout << upper_bound(nums.begin(), nums.end(), 1) - nums.begin();
        int sz = nums.size();
        vector<int> stk;
        for(int i = 0;i < sz;i ++){
            int x = nums[i], sz_stk = stk.size();
            if(sz_stk == 0 || x > stk[sz_stk - 1]){
                stk.push_back(nums[i]);
            }
            else if(x < stk[sz_stk - 1]){
                int pos = upper_bound(stk.begin(), stk.end(), x) - stk.begin();
                stk[pos] = x;
            }
        }
        return stk.size();
    }
};


int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    Solution s;
    vector<int> nums = {1, 5, 3, 2, 7, 5, 4, 2};
    s.lengthOfLIS(nums);
    return 0;
}