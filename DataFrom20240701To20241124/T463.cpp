#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i = 0;i < n;i ++){
            for(int j = 0;j < m;j ++){
                if(!vis[i][j] && grid[i][j]){
                    vis[i][j] = 1;
                    Dfs(grid, vis, i, j);
                }
            }
        }
        return cnt;
    }
    void Dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int x, int y){
        for(int i = 0;i < 4;i ++){
            int Nextx = x + Dir[i][0];
            int Nexty = y + Dir[i][1];
            if(Nextx >= n || Nextx < 0){cnt ++; continue;}
            if(Nexty >= m || Nexty < 0){cnt ++; continue;}
            if(!vis[Nextx][Nexty] && grid[Nextx][Nexty]){
                vis[Nextx][Nexty] = 1;
                Dfs(grid, vis, Nextx, Nexty);
            }
            if(!grid[Nextx][Nexty]) cnt ++;
        }
    }
private:
    int n, m;
    int cnt = 0;
    int Dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
};
int main(){
    return 0;
}