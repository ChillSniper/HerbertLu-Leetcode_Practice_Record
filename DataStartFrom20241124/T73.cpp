#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define Test

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int row_0 = false, col_0 = false;
        for(int i = 0;i < m;i ++){
            if(matrix[i][0] == 0){
                row_0 = true;
                break;
            }
        }
        for(int j = 0;j < n;j ++){
            if(matrix[0][j] == 0){
                col_0 = true;
                break;
            }
        }
        for(int i = 1;i < m;i ++){
            for(int j = 1;j < n;j ++){
                if(!matrix[i][j]){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i = 0;i < m;i ++){
            if(matrix[i][0] == 0){
                for(int j = 1;j < n;j ++){
                    matrix[i][j] = 0;
                }
            }
        }
        for(int j = 0;j < n;j ++){
            if(matrix[0][j] == 0){
                for(int i = 1;i < m;i ++){
                    matrix[i][j] = 0;
                }
            }
        }
        if(row_0){
            for(int i = 0;i < m;i ++) matrix[i][0] = 0;
        }
        if(col_0){
            for(int j = 0;j < n;j ++) matrix[0][j] = 0;
        }
    }
};

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif

    return 0;
}