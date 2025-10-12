#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = needle.size();
        vector<int> Nxt(n + 10, 0);
        Nxt[0] = -1;
        for(int i = 0;i < n;i ++){
            int k = Nxt[i];
            while (k >= 0 && needle[i] != needle[k])
            {
                k = Nxt[k];
            }
            Nxt[i + 1] = ++ k;
        }
        int m = haystack.size();
        for(int i = 0, j = 0;i < m && j < n;){
            if(j < 0 || haystack[i] == needle[j]){
                i ++; j ++;
                if(j == n) return i - n;
            }
            if(needle[j] != haystack[i]){
                j = Nxt[j];
            }
        }
        return -1;
    }
};
