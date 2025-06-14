#include <iostream>
#include <cstdio>
#include <vector>
//#define Way1
#define Way2
using namespace std;

#ifdef Way2
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for(int i = 1;i <= target;i ++){
            for(auto j : nums){
                if(j <= i) dp[i] += dp[i - j];
            }
        }
        return dp[target];
    }
};
#endif

#ifdef Way1
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        // 这题的核心思想居然是动态规划
        int n = nums.size();
        vector<int> memo(n + 1, -1);
        memo[0] = 1; // pay attention to it
        return Dfs(target, nums, memo);
    }
private:
    int Dfs(int cur, vector<int>& nums, vector<int>& memo){
        if(cur == 0) return memo[cur];
        int res = memo[cur];
        if(res != -1) return res;
        int ans = 0;
        for(auto i : nums){
            if(i <= cur) ans += Dfs(cur - i, nums, memo);
        }
        memo[cur] = ans;
        return ans;
    }
};
#endif