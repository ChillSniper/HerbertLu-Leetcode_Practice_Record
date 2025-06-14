#include <iostream>
#include <cstdio>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        n = digits.size();
        if(n == 0) return {};
        mp[2] = "abc"; mp[3] = "def"; mp[4] = "ghi";
        mp[5] = "jkl"; mp[6] = "mno"; mp[7] = "pqrs";
        mp[8] = "tuv"; mp[9] = "wxyz";
        dfs(tmp, digits, 0);
        return ans;
    }
private:
    vector<string> ans;
    vector<char> tmp;
    unordered_map<char, string> mp;
    int n;
    void dfs(vector<char>& cur, string& digits, int index){
        if(index >= n){
            int size = tmp.size();
            if(size == 0) return ;
            string p;
            for(int i = 0;i < size;i ++) p += tmp[i];
            ans.push_back(p);
            return ;
        }
        string s = mp[digits[index] - '0'];
        for(int i = 0;i < s.size();i ++){
            cur.push_back(s[i]);
            dfs(cur, digits, index + 1);
            cur.pop_back();
        }
    }
};