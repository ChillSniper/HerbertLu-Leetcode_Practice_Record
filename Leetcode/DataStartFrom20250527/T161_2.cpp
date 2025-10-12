#include <bits/stdc++.h>
using namespace std;

int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int cnt = 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for(int i = 0;i < m;i ++){
            for(int j = 0;j < n;j ++){
                if(vis[i][j]){
                    continue;
                }
                if(grid[i][j] == 0){
                    continue;
                }
                int sum_cur = 0;
                // vis[i][j] = 1;
                deque<pair<int, int>> dq;
                dq.push_back(make_pair(i, j));
                while (dq.size())
                {
                    pair<int, int> p = dq.front(); dq.pop_front();
                    int x = p.first, y = p.second;
                    if(vis[x][y] == 1){
                        continue;
                    }
                    vis[x][y] = 1;
                    sum_cur = (sum_cur + grid[x][y]) % k;
                    
                    for(int index = 0;index < 4;index ++){
                        int nx = x + dir[index][0];
                        int ny = y + dir[index][1];
                        if(nx < 0 || nx >= m || ny < 0 || ny >= n){
                            continue;
                        }
                        if(vis[nx][ny] == 1){
                            continue;
                        }
                        if(grid[nx][ny] == 0){
                            vis[nx][ny] = 1;
                            continue;
                        }
                        dq.push_back(make_pair(nx, ny));
                    }
                }
                if(sum_cur % k == 0){
                    ++ cnt;
                }
            }
        }
        return cnt;
    }
};

int main(){
    return 0;
}