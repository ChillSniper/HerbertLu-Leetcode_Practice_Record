#include <bits/stdc++.h>
using namespace std;

#define Test

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        // how to deal this f**king problem ?
        int m = matrix.size(), n = matrix[0].size(), ans = 0;
        vector<vector<int>> f(m, vector<int>(n, 0));
        for (int i = 0;i < m;i ++) {
            for (int j = 0;j < n;j ++) {
                int Min = 0x3f3f3f3f;
                if(i > 0 && j > 0) {
                    Min = min(min(f[i - 1][j - 1], f[i - 1][j]), f[i][j - 1]) + 1;
                }
                else if(i > 0 && j <= 0) {
                    Min = f[i - 1][j] + 1;
                }
                else if(i <= 0 && j > 0) {
                    Min = f[i][j - 1] + 1;
                }
                else {
                    Min = 0;
                }
                if(matrix[i][j] == 0) {
                    Min = 0;
                }
                f[i][j] = Min;
                ans += Min;
            }
        } 
        return ans;
    }
};

int main() {
    return 0;
}