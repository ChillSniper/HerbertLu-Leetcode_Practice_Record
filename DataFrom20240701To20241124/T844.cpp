#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int SlowPointerS = 0;
        for(int i = 0;i < s.size();i ++){
            if(s[i] != '#'){
                s[SlowPointerS ++] = s[i];
            }else {
                if(SlowPointerS)
                SlowPointerS -= 1;
                s[SlowPointerS] = ' ';
            }
        }
        int SlowPointerT = 0;
        for(int i = 0;i < t.size();i ++){
            if(t[i] != '#'){
                t[SlowPointerT ++] = t[i];
            }else {
                if(SlowPointerT)
                SlowPointerT --;
                t[SlowPointerT] = ' ';
            }
        }
        for(int i = 0;i < max(SlowPointerS, SlowPointerT);i ++){
            if(s[i] != t[i]) return false;
        }
        return true;
    }
};

int main(){
    freopen("file.in", "r", stdin);
    freopen("file.out", "w", stdout);
    string str1, str2;
    cin >> str1 >> str2;
    Solution s;
    if(s.backspaceCompare(str1, str2))
        printf("Yes");
    else printf("Wrong");
    return 0;
}