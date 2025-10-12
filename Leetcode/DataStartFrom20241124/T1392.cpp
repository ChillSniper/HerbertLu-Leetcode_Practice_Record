#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();
        vector<int> Nxt(n + 10, 0);
        Nxt[0] = -1;
        for(int i = 0;i <= n;i ++){
            int k = Nxt[i];
            while (k >= 0 && s[i] != s[k])
            {
                k = Nxt[k];
            }
            Nxt[i + 1] = ++ k;
        }
        string ans;
        for(int i = 0;i < Nxt[n];i ++)
            ans += s[i];
        return ans;
    }
};