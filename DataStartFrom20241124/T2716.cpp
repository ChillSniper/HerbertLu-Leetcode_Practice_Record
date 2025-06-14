#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimizedStringLength(string s) {
        int ans = 0, sz = s.size();
        for(int i = 0;i < sz;i ++){
            int j = i;
            char ch = s[i];
            while (j < sz && s[j] == ch)
            {
                j ++;
            }
            i = j - 1;
            ans ++;
        }
        return ans;
    }
};