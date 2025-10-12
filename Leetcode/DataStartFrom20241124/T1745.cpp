#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    bool checkPartitioning(string s) {
        // 但是这个做法的时间复杂度很差 达到了O(n ^ 2)
        // 如何进行优化 ？
        
        int sz = s.size();
        vector<vector<int>> f(sz + 1, vector<int>(sz + 1, 1));
        for(int i = sz - 1;i >= 0;i --){
            for(int j = i + 1;j < sz;j ++)
                f[i][j] = f[i + 1][j - 1] && (s[i] == s[j]);
        }
        int i = 0, j = sz - 1;
        for(int j = sz - 1;j >= 0;j --){
            for(int i = 0;j - i >= 2;i ++){
                if(f[0][i] && f[i + 1][j - 1] && f[j][sz - 1])
                    return true;
            }
        }
        return false;
    }
};