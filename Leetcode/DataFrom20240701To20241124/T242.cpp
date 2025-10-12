#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int data[26];
        for(int i = 0;i < 26;i ++) data[i] = 0;
        for(int i = 0;i < s.length();i ++) data[s[i] - 'a'] ++;
        for(int i = 0;i < t.length();i ++) data[t[i] - 'a'] --;
        for(int i = 0;i < 26;i ++){
            if(data[i]) return false;
        }
        return true;
    }
};
