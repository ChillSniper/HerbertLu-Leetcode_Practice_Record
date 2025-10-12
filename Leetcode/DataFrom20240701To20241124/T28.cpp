#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        const int N = 1e4 + 10;
        int Next[N] = {0}, m = needle.length(), n = haystack.length();
        Next[0] = -1;
        for(int i = 0;i < m;i ++){
            int k = Next[i];
            while (k >= 0 && needle[i] != needle[k])
            {
                k = Next[k];
            }
            Next[i + 1] = ++ k;
            // if(k >= 0 && needle[i + 1] != needle[k + 1]) Next[i + 1] = k + 1;
            // else if(k >= 0 && needle[i + 1] == needle[k + 1]) Next[i + 1] = Next[k + 1];
            // else if(needle[i + 1] != needle[k + 1]) Next[i + 1] = 0;
            // else Next[i + 1] = -1; 
        }
        for(int i = 0, j = 0;i < n && j < m;){
            if(j < 0 || haystack[i] == needle[j]){
                i ++;
                j ++;
                if(j == m) return i - m;
            } else{
                j = Next[j];
            }
        }
        return -1;
    }
};

int main(){
    freopen("file.in", "r", stdin);
    freopen("file.out", "w", stdout);
    Solution s;
    cout << s.strStr("aabaaabaaac", "aabaaac");
    return 0;
}