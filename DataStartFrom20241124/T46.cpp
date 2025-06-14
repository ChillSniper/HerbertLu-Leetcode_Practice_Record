#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        // 1 2 3 4 5 6
        vector<int> store;
        Dfs(nums, 0, store);
        return ans;
    }
private:
    vector<vector<int>> ans;
    void Dfs(vector<int>& nums, int st, vector<int>& x){
        int sz = nums.size();
        if(st >= sz){
            ans.push_back(x);
            return ;
        }
        for(int i = st;i < sz;i ++){
            x.push_back(nums[i]);
            int t = nums[i];
            for(int j = i - 1;j >= st;j --)
                nums[j + 1] = nums[j];
            Dfs(nums, st + 1, x);
            x.pop_back();
            for(int j = st;j <= i - 1;j ++)
                nums[j] = nums[j + 1];
            nums[i] = t;
        }
    }
};