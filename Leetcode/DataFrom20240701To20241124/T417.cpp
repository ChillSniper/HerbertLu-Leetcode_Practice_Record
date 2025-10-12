#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
#define Test

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size(), m = heights[0].size();
        vector<vector<int>> Pacific(n, vector<int>(m, 0));
        vector<vector<int>> Atlantic(n, vector<int>(m, 0));
        for(int i = 0;i < n;i ++){
            Dfs(heights, Pacific, i, 0);
            Dfs(heights, Atlantic, i, m - 1);
        }
        for(int j = 0;j < m;j ++){
            Dfs(heights, Pacific, 0, j);
            Dfs(heights, Atlantic, n - 1, j);
        }
        vector<vector<int>> ans;
        for(int i = 0;i < n;i ++){
            for(int j = 0;j < m;j ++){
                if(Pacific[i][j] && Atlantic[i][j]){
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
private:
    void Dfs(vector<vector<int>>& graph, vector<vector<int>>& vis, int x, int y){
        vis[x][y] = 1;
        for(int i = 0;i < 4;i ++){
            int Nextx = x + dir[i][0];
            int Nexty = y + dir[i][1];
            if(Nextx < 0 || Nextx >= n || Nexty < 0 || Nexty >= m) continue;
            if(!vis[Nextx][Nexty] && graph[Nextx][Nexty] >= graph[x][y]){
                Dfs(graph, vis, Nextx, Nexty);
            }
        }
    }
    int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
    int n, m;
};

int main(){

    return 0;
}