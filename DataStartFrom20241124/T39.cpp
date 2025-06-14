#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

#define Test

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> store;
        Dfs(candidates, 0, 0, target, store);
        return ans;
    }
private:
    void Dfs(vector<int>& candidate, int index, int cursum, int target, vector<int>& store){
        int sz = candidate.size();
        if(index >= sz){
            if(cursum == target){
                ans.push_back(store);
            }
            return ;
        }
        if(cursum > target)
            return ;
        if(cursum == target){
            ans.push_back(store);
            return ;
        }
        int x = candidate[index];
        Dfs(candidate, index + 1, cursum, target, store);
        for(int i = 1;i * x <= target;i ++){
            cursum += x;
            for(int j = 1;j <= i;j ++)
                store.push_back(x);
            Dfs(candidate, index + 1, cursum, target, store);
            for(int j = 1;j <= i;j ++)
                store.pop_back();
        }
    }
    vector<vector<int>> ans;
};

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    return 0;
}