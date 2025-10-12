#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
#define Test
class Solution {
public:
    int minCut(string s) {
        // 本题数据范围很大 动态规划问题
        int sz = s.size();
        vector<int> f(sz + 1, 0);
        vector<vector<int>> g(sz, vector<int>(sz, 1));
        for(int i = sz - 1;i >= 0;i --){
            for(int j = i + 1;j < sz;j ++){
                g[i][j] = g[i + 1][j - 1] && (s[i] == s[j]);
            }
        }
        // 实际上问题从何入手呢？
        // bcbabababcba
        // f(i, j) = min(f(i - 1, ));
        for(int i = 0;i < sz;i ++){
            if(g[0][i] == 1){
                f[i] = 0;
            } else{
                for(int j = 0;j < i;j ++){
                    if(g[j + 1][i]){
                        f[i] = min(f[i], f[j] + 1);
                    }
                }
            }
        }
        return f[sz - 1];
    }
};
int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    return 0;
}