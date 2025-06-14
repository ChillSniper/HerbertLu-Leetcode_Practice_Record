#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // 实际上，这题是将数据排序后转换成为树形结构，然后进行剪枝去重
        n = candidates.size();
        vis = vector<int>(n, 0); 
        vector<int> tmp;
        sort(candidates.begin(), candidates.end());
        Dfs(candidates, target, 0, tmp);
        return ans;
    }
private:
    void Dfs(vector<int>& candidates, int cur, int index, vector<int>& tmp){
        if(cur == 0)
            ans.push_back(tmp); return ;
        if(index >= n || cur < 0) return;
        for(int i = index;i < n;i ++){
            if(i > 0 && candidates[i] == candidates[i - 1] && !vis[i - 1]) continue;
            tmp.push_back(candidates[i]);
            vis[i] = 1;
            Dfs(candidates, cur - candidates[i], i + 1, tmp);
            tmp.pop_back();
            vis[i] = 0;
        }
    }
    vector<vector<int>> ans;
    vector<int> vis;
    int n;
};