#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
#define Test
int PerimeterOfGraph, dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1}, n, m;
void TravelGraph(vector<vector<int>>& graph, vector<vector<int>>& vis);
void Dfs(vector<vector<int>>& graph, vector<vector<int>>& vis, int x, int y);
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
    TravelGraph(graph, vis);
    printf("%d", PerimeterOfGraph);
    return 0;
}
void TravelGraph(vector<vector<int>>& graph, vector<vector<int>>& vis){
    for(int i = 0;i < n;i ++){
        for(int j = 0;j < m;j ++){
            if(!vis[i][j] && graph[i][j]){
                Dfs(graph, vis, i, j);
            }
        }
    }
}
void Dfs(vector<vector<int>>& graph, vector<vector<int>>& vis, int x, int y){
    vis[x][y] = 1;
    for(int i = 0;i < 4;i ++){
        int Nextx = x + dir[i][0];
        int Nexty = y + dir[i][1];
        if(Nextx < 0 || Nextx >= n || Nexty < 0 || Nexty >= m){
            PerimeterOfGraph ++;
            continue;
        }
        if(!vis[Nextx][Nexty] && graph[Nextx][Nexty]){
            Dfs(graph, vis, Nextx, Nexty);
        } else if(!graph[Nextx][Nexty]){
            PerimeterOfGraph ++;
        }
    }
}