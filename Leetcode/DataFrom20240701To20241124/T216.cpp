#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> tmp;
        dfs(k, n, 1, tmp);
        return ans;
    }
private:
    void dfs(int k, int cur, int index, vector<int>& tmp){
        if(cur == 0 && k == 0){
            ans.push_back(tmp); return;
        }
        if(cur < 0 || index > 9 || cur == 0 && k > 0 || cur > 0 && k == 0) return;
        tmp.push_back(index);
        dfs(k - 1, cur - index, index + 1, tmp);
        tmp.pop_back();
        dfs(k, cur, index + 1, tmp);
    }
    vector<vector<int>> ans;
};