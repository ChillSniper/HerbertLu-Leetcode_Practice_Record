#include <bits/stdc++.h>
using namespace std;
#define Test

class Solution {
public:
    int strStr(string haystack, string needle) {
        int t_sz = needle.size();
        vector<int> Nxt(t_sz + 10, 0);
        Nxt[0] = -1;
        for (int i = 0;i < t_sz;i ++) {
            // 很久没写kmp又全部忘光了，注意Nxt_i指的是每次对needle_i匹配失败后，下一个相同前后缀之后一个位置匹配的index
            int k = Nxt[i];
            while (k >= 0 && needle[i] != needle[k])
            {
                k = Nxt[k];
            }
            Nxt[i + 1] = ++ k;
        }
        int m = haystack.size();
        for (int i = 0, j = 0;i < m && j < t_sz;) {
            if(haystack[i] == needle[j]) {
                ++ i;
                ++ j;
                if(j == t_sz) {
                    return i - t_sz;
                }
            }
            else {
                j = Nxt[j];
            }
        }
        return -1;
    }
};

int main() {
    #ifdef Test
    #endif
    return 0;
}