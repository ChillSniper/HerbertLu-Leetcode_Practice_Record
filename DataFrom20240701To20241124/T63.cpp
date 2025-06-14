#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
#define Test

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        int ans[205] = {0};
        for(int i = 0;i < m && !obstacleGrid[0][i];i ++){
            ans[i + 1] = 1;
        }
        for(int i = 1;i < n;i ++){
            for(int j = 0;j < m;j ++){
                if(obstacleGrid[i][j]) ans[j + 1] = 0;
                else {
                    ans[j + 1] = ans[j + 1] + ans[j];
                }
            }
        }
        return ans[m];
    }
};

int main(){
    #ifdef Test
    freopen("file.in", "r", stdin);
    freopen("file.out", "w", stdout);
    #endif

    return 0;
}