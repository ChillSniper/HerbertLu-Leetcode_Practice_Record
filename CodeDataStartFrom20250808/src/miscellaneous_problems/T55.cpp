#include <bits/stdc++.h>
using namespace std;

#define Test

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int st = 0;
        vector<int> vis(n, 0);
        deque<int> dq;
        dq.push_back(st);
        while ((int)dq.size())
        {
            int p = dq.front();
            dq.pop_front();
            if(vis[p]) {
                continue;
            }
            vis[p] = 1;
            int nx_max = p + nums[p];
            if(nx_max >= n - 1) {
                return true;
            }
            for (int i = p + 1;i <= min(nx_max, n - 1);i ++) {
                if(!vis[i]) {
                    dq.push_back(i);
                }
            }
        }
        return false;
    }
};

int main() {
    return 0;
}