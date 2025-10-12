#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sz = nums.size(), s = 0, sum = 0;
        for(int i = 0;i < sz;i ++)
            s += nums[i];
        int res = (target + s) / 2;
        vector<int> f(res + 1, 0);
        for(int i = 1;i <= sz;i ++){
            int x = nums[i - 1];
            sum += x;
            for(int j = min(res, sum);j >= x;j --)
                f[j] = f[j] + f[j - x];
        }
        return f[res];
    }
};

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    return 0;
}