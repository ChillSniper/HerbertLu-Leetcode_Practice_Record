#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, n = prices.size();
        int lw = prices[0], hi = prices[0];
        for (int i = 1;i < n;i ++) {
            int cur_val = prices[i];
            if(cur_val >= hi) {
                hi = cur_val;
            }
            else {
                ans += hi - lw;
                lw = cur_val;
                hi = cur_val;
            }
        }
        ans += hi - lw;
        return ans;
    }
};