#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
        vector<int> cur;
        Dfs(nums, 0, cur);
        return ans;
    }
private:
    void Dfs(vector<int>& nums, int index, vector<int>& cur){
        if(index == n){
            ans.push_back(cur);
            return;
        }
        cur.push_back(nums[index]);
        Dfs(nums, index + 1, cur);
        cur.pop_back();
        Dfs(nums, index + 1, cur);
    }
    int n;
    vector<vector<int>> ans;
};