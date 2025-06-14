#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
#define Test

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0, n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i = 0;i < n;i ++){
            for(int j = 0;j < m;j ++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    cnt ++;
                    Dfs(grid, vis, i, j);
                }
            }
        }
        return cnt;
    }
    void Dfs(vector<vector<char>>& grid, vector<vector<int>>& vis, int x, int y){
        int n = grid.size(), m = grid[0].size();
        if(x < 0 || x >= n || y < 0 || y >= m || vis[x][y]) return ;
        vis[x][y] = 1;
        if(grid[x][y] == '0') 
            return ;
        for(int i = 0;i < 4;i ++){
            int Nxt_x = x + direction[i][0], Nxt_y = y + direction[i][1];
            if(Nxt_x < 0 || Nxt_x >= n || Nxt_y < 0 || Nxt_y >= m || vis[Nxt_x][Nxt_y]) continue;
            Dfs(grid, vis, Nxt_x, Nxt_y);
        }
    }
private:
    int direction[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
};

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif

    return 0;
}