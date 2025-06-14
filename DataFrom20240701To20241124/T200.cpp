#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
#define Test
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size(); m = grid[0].size();
        int cnt = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i = 0;i < n;i ++){
            for(int j = 0;j < m;j ++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    cnt ++;
                    vis[i][j] = 1;
                    Dfs(grid, vis, i, j);
                }
            }
        }
        return cnt;
    }
private:
    void Dfs(vector<vector<char>>& grid, vector<vector<int>>& vis, int x, int y){
        for(int i = 0;i < 4;i ++){
            int Nextx = x + Dir[i][0], Nexty = y + Dir[i][1];
            if(Nextx >= n || Nextx < 0 || Nexty >= m || Nexty < 0) continue;
            if(!vis[Nextx][Nexty] && grid[Nextx][Nexty] == '1'){
                vis[Nextx][Nexty] = 1;
                Dfs(grid, vis, Nextx, Nexty);
            }
        }
    }
    int Dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // Dir[x][y] // row, col
    int n, m;
};
int main(){
    #ifdef Test
    freopen("file.in", "r", stdin);
    freopen("file.out", "w", stdout);
    #endif

    return 0;
}