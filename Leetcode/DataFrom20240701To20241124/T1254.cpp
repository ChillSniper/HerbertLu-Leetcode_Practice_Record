#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        vis = vector<vector<int>>(n, vector<int>(m, 0));
        AreaCnt = 0;
        for(int i = 1;i < n - 1;i ++){
            for(int j = 1;j < m - 1;j ++){
                if(!vis[i][j] && !grid[i][j]){
                    vis[i][j] = 1;
                    if(Dfs(grid, vis, i, j))
                        AreaCnt ++;
                }
            }
        }
        return AreaCnt;
    }
private:
    bool Dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int x, int y){
        int flag = 0;
        for(int i = 0;i < 4;i ++){
            int Nextx = x + Dir[i][0];
            int Nexty = y + Dir[i][1];
            if(Nextx >= n || Nextx < 0) continue;
            if(Nexty >= m || Nexty < 0) continue;
            if(!vis[Nextx][Nexty] && !grid[Nextx][Nexty]){
                vis[Nextx][Nexty] = 1;
                if(Nextx == 0 || Nextx == n - 1 || Nexty == 0 || Nexty == m - 1) flag = 1;
                if(!Dfs(grid, vis, Nextx, Nexty)) flag = 1;
            }
        }
        return flag == 0 ? true : false; 
    }
    int Dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // Dir[x][y] // row, col
    int n, m, AreaCnt;
    vector<vector<int>> vis;
};