#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define Test
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0, MaxNum = 0, sz = nums.size();
        for(int i = 0;i < sz;i ++){
            sum += nums[i];
            MaxNum = max(MaxNum, nums[i]);
        }
        if(sum % 2)
            return false;
        if(MaxNum > sum / 2)
            return false;
        int target = sum / 2;
        vector<vector<int>> f(sz, vector<int>(sum + 1, 0));
        for(int i = 0;i < sz;i ++)
            f[i][0] = 1;
        int s = nums[0];
        f[0][nums[0]] = 1;
        for(int i = 1;i < sz;i ++){
            s += nums[i];
            
            for(int j = s;j >= nums[i];j --)
                f[i][j] = f[i - 1][j] || f[i - 1][j - nums[i]];
            for(int j = nums[i] - 1;j >= 0;j --)
                f[i][j] = f[i - 1][j];
        }
        return f[sz - 1][target];
    }
};
int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    vector<int> num = {1, 5, 10, 6};
    Solution s;
    cout << s.canPartition(num);
    return 0;
}