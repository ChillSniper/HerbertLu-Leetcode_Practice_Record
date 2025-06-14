#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define Test

class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int maxn_num = 0, curn_num = 0, res_i = -1;
        for(int i = 0;i < m;i ++){
            curn_num = 0;
            for(int j = 0;j < n;j ++){
                if(mat[i][j] == 1){
                    curn_num ++;
                }
            }
            if(curn_num > maxn_num){
                maxn_num = curn_num;
                res_i = i;
            }
        }
        return {res_i, maxn_num};
    }
};

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif

    return 0;
}