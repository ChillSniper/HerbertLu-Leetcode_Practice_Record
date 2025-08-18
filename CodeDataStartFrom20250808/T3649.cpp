#include <bits/stdc++.h>
using namespace std;

#define Test

typedef long long ll;
class Solution {
public:
    long long perfectPairs(vector<int>& nums) {
        // 这道题比赛时其实挺遗憾的，当时没有考虑到，可以对这个数组进行排序然后使用贪心解决。。。
        // 这个题的问题是什么呢，就是说，对于任意两个数，都要比较过去，然后不要重复比较即可，所以我们可以对它排个序
        sort(nums.begin(), nums.end());
        ll ans = 0;
        int n = nums.size();
        int sl = 0, fs = 0;
        for (;fs < n && sl <= fs;) {
            int cur_val = nums[sl];
            while (fs < n && nums[fs] <= 2 * cur_val)
            {
                ++ fs;
            }
            ans += (fs - sl);
            if(sl == fs) {
                ++ fs;
            }
            ++ sl;
        }
        return ans;
        // 第二个max条件恒成立
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
    }
};


int main() {
    return 0;
}