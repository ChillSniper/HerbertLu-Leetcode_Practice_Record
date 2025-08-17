#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        long long ans = 0;
        int n = prices.size();
        for (int i = 0;i < n;i ++) {
            ans += prices[i] * strategy[i];
        }
        vector<int> ori_strategy = strategy;
        for (int i = 0;i < k / 2;i ++) {
            strategy[i] = 0;
        }
        for (int i = k / 2;i < k;i ++) {
            strategy[i] = 1;
        }
        long long cur = 0;
        for (int i = 0;i < n;i ++) {
            cur += prices[i] * strategy[i];
        }
        ans = max(ans, cur);
        int l_l = 0, l_r = k / 2 - 1, r_l = k / 2, r_r = k - 1;
        for (;r_r < n;) {
            if (r_r + 1 >= n) {
                break;
            }
            cur = cur - prices[l_l] * strategy[l_l];
            strategy[l_l] = ori_strategy[l_l];
            cur += prices[l_l] * strategy[l_l];
            l_l ++;
            l_r ++;
            cur = cur - prices[r_l] * strategy[r_l];
            strategy[r_l] = 0;
            // ^
            r_l ++;
            ++ r_r;
            cur = cur - prices[r_r] * strategy[r_r];
            strategy[r_r] = 1;
            cur = cur + prices[r_r];
            ans = max(ans, cur);
        }
        return ans;
    }
};