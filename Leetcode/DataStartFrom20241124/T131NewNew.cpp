#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        int sz = s.size();
        vector<vector<int>> f(sz + 1, vector<int>(sz + 1, 1));
        for(int j = sz - 1;j >= 0;j --){
            for(int i = j + 1;i < sz;i ++){
                f[i][j] = f[i - 1][j + 1] && (s[i] == s[j]);
            }
        }
        vector<string> store;
        Dfs(s, 0, store, f);
        return ans;
    }

private:
    vector<vector<string>> ans;
    void Dfs(string& s, int index, vector<string>& store, vector<vector<int>>& f){
        int sz = s.size();
        if(index >= sz){
            ans.push_back(store);
            return ;
        }
        for(int i = index;i < sz;i ++){
            if(f[index][i]){
                store.push_back(s.substr(index, i - index + 1));
                Dfs(s, i + 1, store, f);
                store.pop_back();
            }
        }
    }
};