#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n = candidates.size();
    }
private:
    void Dfs(vector<int>& candidates, int current, int index, vector<int>& tmp){
        if(current == 0){
            ans.push_back(tmp); return;
        }
        if(index >= n || current < 0) return;
        for(int i = index;i < n;i ++){
            tmp.push_back(candidates[index]);
            Dfs(candidates, current - candidates[i], i, tmp);
            tmp.pop_back();
        }
    }
    vector<vector<int>> ans;
    int n;
};