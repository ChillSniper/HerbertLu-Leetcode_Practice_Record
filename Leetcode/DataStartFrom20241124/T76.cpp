#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
#define Test

class Solution {
public:
    string minWindow(string s, string t) {
        int sl = 0, fs = 0, MinLen = 0x3f3f3f3f, sz_s = s.size(), sz_t = t.size(), NumOfs[300] = {0}, NumOft[300] = {0}, differ = 0;
        string ans = "";
        for(int i = 0;i < sz_t;i ++) NumOft[t[i]] ++;
        for(int i = 0;i < 300;i ++){
            if(NumOfs[i] != NumOft[i]) differ ++;
        }
        for(;sl <= fs && fs < sz_s;){
            int oris = NumOfs[s[fs]], orit = NumOft[s[fs]];
            NumOfs[s[fs]] ++;
            if(NumOfs[s[fs]] >= NumOft[s[fs]] && oris < orit && orit) differ --;
            else if(NumOfs[s[fs]] < NumOft[s[fs]] && oris >= orit && orit) differ ++;
            fs ++;
            if(differ != 0) continue;
            else{
                while (differ == 0 && sl < fs)
                {
                    oris = NumOfs[s[sl]];
                    orit = NumOft[s[sl]];
                    NumOfs[s[sl]] --;
                    if(NumOfs[s[sl]] >= NumOft[s[sl]] && oris < orit && orit) differ --;
                    else if(NumOfs[s[sl]] < NumOft[s[sl]] && oris >= orit && orit) differ ++;
                    sl ++;
                }
                int len = fs - (sl - 1);
                if(len < MinLen){
                    MinLen = len;
                    ans = s.substr(sl - 1, len);
                }
            }
        }
        return ans;
    }
};

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    string s = "ADOBECODEBANC", t = "ABC";
    Solution exam;
    cout << exam.minWindow(s, t);
    return 0;
}