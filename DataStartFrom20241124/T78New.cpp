#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> store;
        Dfs(nums, 0, store);
        return ans;
    }
private:
    void Dfs(vector<int>& num, int index, vector<int>& store){
        int sz = num.size();
        if(index >= sz){
            ans.push_back(store);
            return ;
        }
        Dfs(num, index + 1, store);
        store.push_back(num[index]);
        Dfs(num, index + 1, store);
        store.pop_back();
    }
    vector<vector<int>> ans;
};