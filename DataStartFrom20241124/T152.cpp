#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

#define Test

typedef long long ll;
ll INF = INT_MIN;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int sz = nums.size();
        ll ans = INF / 2, cur_max = 1, cur_min = 1;
        for(int i = 0;i < sz;i ++){
            int x = nums[i];
            // x, x * cur_max, cur_min * x
            ll last_max = cur_max;
            cur_max = max(max(cur_max * x, cur_min * x), (ll)x);
            // x, x * curmin
            cur_min = min(min(x * last_max, x * cur_min), (ll)x);
            ans = max(cur_max, ans);
        }
        return ans;
    }
};