#include <bits/stdc++.h>
using namespace std;

#define Test

const int INF = 0x3f3f3f3f;

class Solution {
public:
    int jump(vector<int>& nums) {
        int MaxReach = 0, cnt = 0, lf = 0, ri = 0, n = nums.size();
        for (;;) {
            ++ cnt;
            for (int i = lf;i <= ri;i ++) {
                MaxReach = max(MaxReach, i + nums[i]);
                if(MaxReach >= n - 1) {
                    return cnt;
                }
            }
            lf ++;
            ri = MaxReach;
        }
        return -1;
    }
};

int main() {
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    return 0;
}