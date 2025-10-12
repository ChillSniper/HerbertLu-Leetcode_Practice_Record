#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;
#define Test
class Solution {
public:
    int rob(vector<int>& nums) {
        int sz = nums.size();
        vector<int> ans(sz + 1, 0);
        if(sz == 1)
            return nums[0];
        ans[0] = nums[0];
        ans[1] = max(nums[1], nums[0]);
        for(int i = 2;i < sz;i ++){
            ans[i] = max(ans[i - 2] + nums[i], ans[i - 1]);
        }
        return ans[sz - 1];
    }
};
int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    return 0;
}