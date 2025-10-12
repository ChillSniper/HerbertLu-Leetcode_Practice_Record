#include <bits/stdc++.h>
using namespace std;
#define Test

typedef long long ll;
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        // max ans of (nums[i] - nums[j]) * nums[k]
        int sz = nums.size();
        ll ans = 0;
        vector<int> PreMax(sz + 1, 0), sufMax(sz + 1, 0);
        PreMax[0] = nums[0];
        for(int i = 1;i < sz;i ++){
            PreMax[i] = max(nums[i], PreMax[i - 1]);
        }
        for(int i = sz - 1;i >= 0;i --){
            sufMax[i] = max(sufMax[i + 1], nums[i]);
        }
        for(int j = 1;j <= sz - 2;j ++){
            ans = max(ans, (ll)(PreMax[j - 1] - nums[j]) * sufMax[j + 1]);
        }
        return ans;
    }
};