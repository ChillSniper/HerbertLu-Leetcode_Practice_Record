#include <bits/stdc++.h>
using namespace std;

#define Test

class Solution {
public:
    int minimumSum(vector<vector<int>>& grid) {
        // nmd这个有点像智力题，一点头绪没有
        // 我tm人傻了
        // 这种题还是打个暴力得了，一点头绪没有，那个dp做法根本看不懂
        vector<vector<int>> r_matrix = rotate(grid);
        return min(solve(grid), solve(r_matrix));
    }
private:
    vector<vector<int>> rotate(const vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 0));
        for (int i = 0;i < m;i ++) {
            for (int j = 0;j < n;j ++) {
                ans[j][i] = grid[i][j];
            }
        }
        return ans;
    }
    int solve(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int ans = INT_MAX;
        if(m >= 3) {
            for (int i = 1;i < m;i ++) {
                for (int j = i + 1;j < m;j ++) {
                    int area = getMinArea(matrix, 0, i, 0, n);
                    area += getMinArea(matrix, i, j, 0, n);
                    area += getMinArea(matrix, j, m, 0, n);
                    ans = min(ans, area);
                }
            }
        }
        if(m >= 2 && n >= 2) {
            for (int i = 1;i < m;i ++) {
                for (int j = 1;j < n;j ++) {
                    int area1 = getMinArea(matrix, 0, i, 0, n);
                    area1 += getMinArea(matrix, i, m, 0, j);
                    area1 += getMinArea(matrix, i, m, j, n);
                    int area2 = getMinArea(matrix, i, m, 0, n);
                    area2 += getMinArea(matrix, 0, i, 0, j);
                    area2 += getMinArea(matrix, 0, i, j, n);
                    ans = min(ans, area1);
                    ans = min(ans, area2);
                }
            }
        }
        return ans;
    }
    int getMinArea(vector<vector<int>>& matrix, int up, int down, int left, int right) {
        int a_u = down, a_d = up, a_l = right, a_r = left;
        for (int i = up;i < down;i ++) {
            for (int j = left;j < right;j ++) {
                if(matrix[i][j]) {
                    a_u = min(a_u, i);
                    a_d = max(a_d, i);
                    a_l = min(j, a_l);
                    a_r = max(a_r, j);
                }
            }
        }
        return (a_d - a_u + 1) * (a_r - a_l + 1);;
    }
};

int main() {
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    return 0;
}