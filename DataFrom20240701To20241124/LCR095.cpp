#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int ans[text2.length() + 1][text1.length() + 1];
        for(int i = 0;i <= text2.length();i ++){
            for(int j = 0;j <= text1.length();j ++)
                ans[i][j] = 0;
        }
        for(int i = 0;i < text2.length();i ++){
            for(int j = 0;j < text1.length();j ++){
                if(text1[j] == text2[i]) ans[i + 1][j + 1] = ans[i][j] + 1;
                else ans[i + 1][j + 1] = max(ans[i][j + 1], ans[i + 1][j]);
            }
        }
        return ans[text2.length()][text1.length()];
    }
};