#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        n = nums.size();
        vector<int> cur;
        used = vector<int>(n, false);
        Dfs(0, nums, cur);
        return ans;
    }
private:
    int n;
    vector<vector<int>> ans;
    vector<int> used;
    void Dfs(int index, vector<int>& nums, vector<int>& cur){
        // 实际上，对于有重复元素的选取，要记录当前值是否访问过，也就是说，对于当前树枝，和当前树层，要进行讨论过去
        ans.push_back(cur);
        for(int i = index;i < n;i ++){
            if(i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) continue;
            cur.push_back(nums[i]);
            used[i] = true;
            Dfs(i + 1, nums, cur);
            used[i] = false;
            cur.pop_back();
        }
    }
};