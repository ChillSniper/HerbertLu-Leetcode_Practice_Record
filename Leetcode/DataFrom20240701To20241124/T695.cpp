#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vis = vector<vector<int>>(n, vector<int>(m, 0));
        for(int i = 0;i < n;i ++){
            for(int j = 0;j < m;j ++){
                
                if(!vis[i][j] && grid[i][j]){
                    vis[i][j] = 1;
                    CurrentArea = 1;
                    Dfs(grid, i, j);
                    MaxArea = max(MaxArea, CurrentArea);
                }
            }
        }
        return MaxArea;
    }
    void Dfs(vector<vector<int>>& grid, int x, int y){
        for(int i = 0;i < 4;i ++){
            int Nextx = x + Dir[i][0];
            int Nexty = y + Dir[i][1];
            if(Nextx >= n || Nextx < 0) continue;
            if(Nexty >= m || Nexty < 0) continue;
            if(!vis[Nextx][Nexty] && grid[Nextx][Nexty]){
                vis[Nextx][Nexty] = 1;
                CurrentArea ++;
                Dfs(grid, Nextx, Nexty);
            }
        }
    }
private:
    int n, m;
    int CurrentArea = 0, MaxArea = 0;
    vector<vector<int>> vis;
    int Dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
};
int main(){
    return 0;
}