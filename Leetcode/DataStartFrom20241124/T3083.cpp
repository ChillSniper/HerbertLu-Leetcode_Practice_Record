#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

class Solution {
public:
    bool isSubstringPresent(string s) {
        int sz = s.size();
        for(int i = 0;i < sz;i ++){
            if(i + 1 < sz && s[i] == s[i + 1]) return true;
            if(i + 2 < sz && s[i] == s[i + 2]) return true;
        }
        for(int i = 0;i < sz - 1;i ++){
            char a = s[i + 1], b = s[i];
            if(specialJudge(s, a, b)) return true;
        }
        return false;
    }
private:
    bool specialJudge(string& s, char a, char b){
        int sz = s.size();
        for(int i = 0;i < sz - 1;i ++){
            if(s[i] == a && s[i + 1] == b) return true;
        }
        return false;
    }
};