#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define Test
class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();
        vector<int> Nxt(n + 10, 0);
        Nxt[0] = -1;
        for(int i = 0;i  < n;i ++){
            int k = Nxt[i];
            while (k >= 0 && needle[i] != needle[k])
            {
                k = Nxt[k];
            }
            Nxt[i + 1] = ++ k;
        }
        for(int i = 0, j = 0;i < m && j < n;){
            if(j < 0 || haystack[i] == needle[j]){
                ++ i;
                ++ j;
                if(j == n){
                    return i - n;
                }
            }
            else{
                j = Nxt[j];
            } 
        }
        return -1;
    }
};
int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    return 0;
}