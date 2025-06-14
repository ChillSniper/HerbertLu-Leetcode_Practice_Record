#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        n = s.length();
        vector<string> x;
        Dfs(s, 0, x);
        return ans;
    }
private:
    void Dfs(string& s, int index, vector<string>& x){
        if(index == n){
            ans.push_back(x);
            return ;
        }
        string tmp;
        for(int i = index;i < n;i ++){
            tmp += s[i];
            string re = tmp;
            reverse(re.begin(), re.end());
            if(IsSame(tmp, re)){
                x.push_back(tmp);
                Dfs(s, i + 1, x);
                x.pop_back();
            }
        }
    }
    bool IsSame(string a, string b){
        if(a.length() != b.length()) return false;
        int len = a.length();
        for(int i = 0;i < len;i ++)
            if(a[i] != b[i]) return false;
        return true;
    }
    vector<vector<string>> ans;
    int n;
};