#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        // œ»sort“ªœ¬
        // 123456789
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size() - 1;
        long long s = 0;
        while (l < r)
        {
            s += nums[r - 1];
            ++ l;
            r -= 2;
        }
        return s;
    }
};

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    return 0;
}