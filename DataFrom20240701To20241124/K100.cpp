#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
#define Test
int n, m;
int CurrentArea = 0;
int Dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
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
    int MaxArea = 0;
    for(int i = 0;i < n;i ++){
        for(int j = 0;j < m;j ++){
            if(!vis[i][j] && graph[i][j]){
                vis[i][j] = 1;
                CurrentArea = 1;
                Dfs(graph, vis, i, j);
                MaxArea = max(MaxArea, CurrentArea);
            }
        }
    }
    printf("%d", MaxArea);
    return 0;
}
void Dfs(vector<vector<int>>& graph, vector<vector<int>>& vis, int x, int y){
    for(int i = 0;i < 4;i ++){
        int Nextx = x + Dir[i][0];
        int Nexty = y + Dir[i][1];
        if(Nextx >= n || Nextx < 0) continue;
        if(Nexty >= m || Nexty < 0) continue;
        if(!vis[Nextx][Nexty] && graph[Nextx][Nexty]){
            vis[Nextx][Nexty] = 1;
            CurrentArea ++;
            Dfs(graph, vis, Nextx, Nexty);
        }
    }
}