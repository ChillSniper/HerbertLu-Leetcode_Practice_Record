#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        MarkGraph(grid, vis);
        return GetMaxArea(grid, vis);
    }
    int GetMaxArea(vector<vector<int>>& graph, vector<vector<int>>& vis){
        int MaxArea = 0;
        for(auto item : mp)
            MaxArea = max(MaxArea, item.second);
        for(int i = 0;i < n;i ++){
            for(int j = 0;j < m;j ++){
                if(!vis[i][j] && !graph[i][j]){
                    vis[i][j] = 1;
                    unordered_set<int> st;
                    int currentArea = 1;
                    for(int k = 0;k < 4;k ++){
                        int Nexti = i + dir[k][0];
                        int Nextj = j + dir[k][1];
                        if(Nexti >= n || Nexti < 0 || Nextj >= m ||Nextj < 0) continue;
                        int mark = graph[Nexti][Nextj];
                        if(mark && !st.count(mark)){
                            currentArea += mp[mark];
                            st.insert(mark);
                        }
                    }
                    MaxArea = max(MaxArea, currentArea);
                }
            }
        }
        return MaxArea;
    }
    void MarkGraph(vector<vector<int>>& graph, vector<vector<int>>& vis){
        int Mark = 2;
        for(int i = 0;i < n;i ++){
            for(int j = 0;j < m;j ++){
                if(!vis[i][j] && graph[i][j] == 1){
                    mp[Mark] = DfsForMarkAndArea(graph, vis, i, j, Mark);
                    Mark ++;
                }
            }
        }
    }
    int DfsForMarkAndArea(vector<vector<int>>& graph, vector<vector<int>>& vis, int x, int y, int Mark){
        vis[x][y] = 1;
        graph[x][y] = Mark;
        int SumArea = 1;
        for(int i = 0;i < 4;i ++){
            int Nextx = x + dir[i][0];
            int Nexty = y + dir[i][1];
            if(Nextx >= n || Nextx < 0 || Nexty >= m || Nexty < 0) continue;
            if(!vis[Nextx][Nexty] && graph[Nextx][Nexty] == 1){
                SumArea += DfsForMarkAndArea(graph, vis, Nextx, Nexty, Mark);
            }
        }
        return SumArea;
    }
private:
    unordered_map<int, int> mp;
    int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
    int n, m;
};
int main(){
    return 0;
}