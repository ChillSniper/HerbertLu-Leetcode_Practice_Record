#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define Test

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0;i < n / 2;i ++){
            for(int j = 0;j < n;j ++)
                swap(matrix[i][j], matrix[n - 1 - i][j]);
        }
        for(int i = 0;i < n;i ++){
            for(int j = 0;j < i;j ++){
                swap(matrix[i][j], matrix[j][i]);
            }
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