#include <bits/stdc++.h>
using namespace std;
#define Test

typedef long long ll;
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        ll ans = 0;
        int sz = nums.size();
        for(int i = 0;i < sz;i ++){
            for(int j = i + 1;j < sz;j ++){
                for(int k = j + 1;k < sz;k ++){
                    ans = max(ans, (ll)((ll)nums[i] - (ll)nums[j]) * (ll)nums[k]);
                }
            }
        }
        return ans;
    }
};