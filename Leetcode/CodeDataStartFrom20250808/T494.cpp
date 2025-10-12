#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define Test

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // p + q = sum
        // p - q = target
        // so choose the sum of p
        // let p = (sum + target) / 2
        int sum = 0;
        for (auto item : nums) {
            sum += item;
        }
        if((sum + target) % 2 || (sum + target) < 0) {
            return 0;
        }
        // each item has two choice
        // choose or not choose
        // so how to do ?
        int p = (sum + target) / 2;
        vector<int> f(p + 1, 0);
        f[0] = 1;
        int cur_sum = 0, n = nums.size();
        for (int i = 0;i < n;i ++) {
            int cur_val = nums[i];
            cur_sum += cur_val;
            for(int j = min(cur_sum, p);j >= cur_val;j --) {
                if(f[j - cur_val]) {
                    f[j] += f[j - cur_val];
                }
            }
        }
        return f[p];
    }
};

int main() {
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    return 0;
}