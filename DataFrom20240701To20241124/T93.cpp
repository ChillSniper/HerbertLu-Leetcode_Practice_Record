#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        n = s.length();
        vector<char> a;
        Dfs(0, s, 0, a);
        return ans;   
    }
private:
    int n;
    vector<string> ans;
    bool check(string& s){
        int len = s.length();
        for(int i = 0;i < len;i ++){
            int tmp = 0, j = i;
            while (s[j] != '.' && j < len)
            {
                if(tmp > 255) return false;
                tmp = tmp * 10 + s[j] - '0';
                j ++;
            }
            i = j;
            if(tmp > 255) return false;
        }
        return true;
    }
    void Dfs(int cnt, string& OriginalS, int index, vector<char> a){
        if(index >= n){
            if(cnt == 4){
                string s;
                int a_size = a.size();
                for(int i = 0;i < a_size - 1;i ++) s += a[i];
                if(check(s))
                    ans.push_back(s);
            }
            return ;
        }
        if(OriginalS[index] == '0'){
            a.push_back('0');
            a.push_back('.');
            Dfs(cnt + 1, OriginalS, index + 1, a);
            return ;
        }
        for(int i = index;i < n;i ++){
            a.push_back(OriginalS[i]);
            a.push_back('.');
            Dfs(cnt + 1, OriginalS, i + 1, a);
            a.pop_back();
        }
    }
};