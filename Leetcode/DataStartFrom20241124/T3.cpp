#include <iostream>
#include <cstdio>
#include <cstring>
#include <unordered_map>
#include <algorithm>
using namespace std;
#define Test

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> ump;
        int sz = s.size(), fs = 0, sl = 0, LongestLen = 0;
        for(;sl <= fs && fs < sz;){
            while ((!ump.count(s[fs]) || ump[s[fs]] == 0) && fs < sz)
            {
                ump[s[fs]] ++;
                fs ++;
            }
            LongestLen = max(LongestLen, fs - sl);
            if(fs == sz){
                break;
            }
            char ch = s[fs];
            while (s[sl] != ch && sl < sz)
            {
                ump[s[sl]] --;
                sl ++;
            }
            if(sl == sz) break;
            else ump.erase(s[sl ++]);
        }
        return LongestLen;
    }
};

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    string s = "tmmzuxt";
    Solution example;
    cout << example.lengthOfLongestSubstring(s);
    return 0;
}