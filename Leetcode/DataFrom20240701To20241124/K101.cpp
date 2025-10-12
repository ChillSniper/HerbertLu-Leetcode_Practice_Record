#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
#define Test
int n, m, currentArea;
int Dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
bool Dfs(vector<vector<int>>& graph, vector<vector<int>>& vis, int x, int y);
int main(){
    #ifdef Test
    freopen("file.in", "r", stdin);
    freopen("file.out", "w", stdout);
    #endif
    scanf("%d%d", &n, &m);
    vector<vector<int>> graph(n, vector<int>(m, 0));
    vector<vector<int>> vis = graph;
    for(int i = 0;i < n;i ++)
        for(int j = 0;j < m;j ++)
            scanf("%d", &graph[i][j]);
    int SumArea = 0;
    for(int i = 1;i < n - 1;i ++){
        for(int j = 1;j < m - 1;j ++){
            if(!vis[i][j] && graph[i][j]){
                vis[i][j] = 1;
                currentArea = 1;
                if(Dfs(graph, vis, i, j)) SumArea += currentArea;
            }
        }
    }
    printf("%d", SumArea);
    return 0;
}
bool Dfs(vector<vector<int>>& graph, vector<vector<int>>& vis, int x, int y){
    int flag = 0;
    for(int i = 0;i < 4;i ++){
        int Nextx = x + Dir[i][0];
        int Nexty = y + Dir[i][1];
        if(Nextx >= n || Nextx < 0) continue;
        if(Nexty >= m || Nexty < 0) continue;
        if(!vis[Nextx][Nexty] && graph[Nextx][Nexty]){
            vis[Nextx][Nexty] = 1;
            if(Nextx == 0 || Nextx == n - 1 || Nexty == 0 || Nexty == m - 1) flag = 1;
            currentArea ++;
            if(!Dfs(graph, vis, Nextx, Nexty)) flag = 1;
        }
    }
    return flag == 0 ? true : false;
}