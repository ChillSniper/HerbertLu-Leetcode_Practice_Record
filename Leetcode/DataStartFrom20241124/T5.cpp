#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define Test

class Solution {
public:
    string longestPalindrome(string s) {
        int sz = s.size();
        vector<vector<int>> f(sz, vector<int>(sz, 0));
        for(int i = 0;i < sz;i ++)
            f[i][i] = 1;
        for(int i = 0;i < sz;i ++){
            for(int j = i - 1;j >= 0;j --){
                if(j + 1 <= i - 1){
                    f[j][i] = f[j + 1][i - 1] && (s[j] == s[i]);
                }
                else{
                    f[j][i] = (s[i] == s[j]);
                }
            }
        }
        int ans = 1;
        string t = string(1, s[0]);
        for(int i = 0;i < sz;i ++){
            for(int j = i + 1;j < sz;j ++){
                if(f[i][j] && j - i + 1 > ans){
                    ans = j - i + 1;
                    t = s.substr(i, j - i + 1);
                }
            }
        }
        return t;
    }
};

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    string s = "cbbd";
    Solution example;
    cout << example.longestPalindrome(s);
    return 0;   
}