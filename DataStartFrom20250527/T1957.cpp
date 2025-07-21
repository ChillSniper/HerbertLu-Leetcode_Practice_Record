#include <bits/stdc++.h>
using namespace std;
#define Test

class Solution {
public:
    string makeFancyString(string s) {
        int n = s.size();
        string ans;
        for(int i = 0;i < n;i ++){
            int j = i;
            while(j + 1 < n && s[j + 1] == s[j]){
                ++ j;
            }
            int len = j - i + 1;
            char ch = s[j];
            i = j;
            len = len >= 3 ? 2 : len;
            if(1){
                for(int index = 0;index < len;index ++){
                    ans += ch;
                }
            }
        }        
        return ans;
    }
};