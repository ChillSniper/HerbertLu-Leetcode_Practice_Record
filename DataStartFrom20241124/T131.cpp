#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define Test
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> store;
        Dfs(store, s, 0);
        return ans;
    }
    void Dfs(vector<string>& store, string& s, int pos){
        int sz = s.size();
        if(pos >= sz){
            ans.push_back(store);
            return ;
        }
        for(int i = pos;i < sz;i ++){
            string tmp = s.substr(pos, i - pos + 1);
            string op = tmp;
            reverse(op.begin(), op.end());
            if(tmp == op){
                store.push_back(tmp);
                Dfs(store, s, i + 1);
                store.pop_back();
            }
        }
    }
private:
    vector<vector<string>> ans;
};

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    // string x = "tesp";
    // string k = x.substr(0, 3);
    // cout << k;
    return 0;
}