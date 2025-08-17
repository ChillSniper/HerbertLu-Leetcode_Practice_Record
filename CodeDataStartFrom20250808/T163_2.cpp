#include <bits/stdc++.h>
using namespace std;

#define Test

typedef long long ll;
class Solution {
public:
    long long perfectPairs(vector<int>& nums) {
        // 第二个max条件无效
        // 我们只要考虑第一个条件
        // a = 0 || b = 0 false
        // a = 0 && b = 0 TRUE
        // a > 0 && b > 0
            // 1.  a >= b
            // a - b <= b
            // b <= a <= 2 * b

            // 2. b >= a
            // b - a <= a
            // a <= b <= 2 * a
            
        // a > 0 && b < 0
            // 1. |a| > |b|
            // a - |b| <= |b|
            // a >= 0
            // |b| <= |a| <= 2 * |b|
        
            // 2. |a| = |b|
            // 0 <= 0
            // True

            // 3. |a| < |b|
            // |b| - a <= |a|
            // |a| <= |b| <= 2 * |a|
        map<int, int> cnt;
        ll ans = 0;
        for (auto item : nums) {
            item = abs(item);
            cnt[item] ++;
        }
        int n = nums.size();
        for (int i = 0;i < n;i ++) { 
            int val = abs(nums[i]);
            cnt[val] --;
            if(cnt[val] == 0) {
                cnt.erase(val);
            }

            auto it = cnt.lower_bound(val);
            for (;it != cnt.end() && it->first <= 2 * val;++ it) {
                ans += it->second;
            }
            // x < val <= 2 * x 
            // 2 * x >= val
            // x >= (val + 1) / 2
            int x = (val + 1) / 2;
            it = cnt.lower_bound(x);
            for (;it != cnt.end() && it->first <= min(2 * x, val - 1);++ it){
                ans += it->second;
            }
        }
        return ans;
    }
};

int main() {
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    vector<int> arr = {1, 10, 100, 1000};
    Solution s;
    s.perfectPairs(arr);
    return 0;
}