#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
#define Test
class Solution {
public:
    vector<vector<string>> partition(string s) {
        int sz = s.size();
        vector<vector<int>> f(sz, vector<int>(sz, 1));
        for(int i = sz - 1;i >= 0;i --){
            for(int j = i;j < sz;j ++){
                f[i][j] = f[i + 1][j - 1] ^ (s[i] == s[j]);
            }
        }
        vector<string> store;
        Dfs(0, s, store, f);
        return ans;
    }
private:
    vector<vector<string>> ans;
    void Dfs(int index, string& s, vector<string>& store, vector<vector<int>>& f){
        int sz = s.size();
        if(index >= sz){
            ans.push_back(store);
            return ;
        }
        for(int i = index;i < sz;i ++){
            if(f[index][i]){
                store.push_back(s.substr(index, i - index + 1));
                Dfs(i + 1, s, store, f);
                store.pop_back();
            }
        }
    }
};