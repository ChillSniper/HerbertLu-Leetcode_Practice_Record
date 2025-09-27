#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int sz = s.size();
        for (int i = 0, j = sz - 1;i < j;i ++, j --) {
            swap(s[i], s[j]);
        }
        s += " ";
        sz = s.size();
        int sl = 0, fs_a = 0, fs_b = 0;
        for (;fs_a < sz && fs_b < sz;) {
            while (fs_a < sz && s[fs_a] == ' ') 
            {
                ++ fs_a;
            }
            fs_b = fs_a;
            while (fs_b < sz && s[fs_b] != ' ')
            {
                ++ fs_b;
            }
            for (int i = fs_a;i < fs_b;i ++) {
                s[sl ++] = s[i ++];
            }
            s[sl ++] = ' ';
            fs_a = fs_b;
        }
        s.resize(sl);
        return s;
    }
};