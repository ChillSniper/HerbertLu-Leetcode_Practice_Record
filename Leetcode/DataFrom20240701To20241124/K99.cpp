#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <deque>
using namespace std;
#define Test
//#define DfsWay
#define BfsWay
int n, m;
int Direction[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
#ifdef BfsWay
void Bfs(vector<vector<int>>& graph, vector<vector<int>>& vis, int x, int y);
#endif
#ifdef DfsWay
int CalculateLandsNumber(vector<vector<int>>& graph);
void Dfs(vector<vector<int>>& graph, vector<vector<int>>& vis, int x, int y);
#endif
int main(){
    #ifdef Test
    freopen("file.in", "r", stdin);
    freopen("file.out", "w", stdout);
    #endif
    scanf("%d%d", &n, &m);
    vector<vector<int>> graph(n, vector<int>(m, 0));
    for(int i = 0;i < n;i ++){
        for(int j = 0;j < m;j ++)
            scanf("%d", &graph[i][j]);
    }
    #ifdef BfsWay
    int cnt = 0;
    n = graph.size();
    m = graph[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    for(int i = 0;i < n;i ++){
        for(int j = 0;j < m;j ++){
            if(!vis[i][j] && graph[i][j]){
                vis[i][j] = 1;
                cnt ++;
                Bfs(graph, vis, i, j);
            }
        }
    }
    printf("%d", cnt);
    #endif
    #ifdef DfsWay
    printf("%d", CalculateLandsNumber(graph));
    #endif
    return 0;
}
#ifdef BfsWay
void Bfs(vector<vector<int>>& graph, vector<vector<int>>& vis, int x, int y){
    deque<pair<int, int>> dq;
    dq.push_back(pair<int, int>(x, y));
    while (!dq.empty())
    {
        pair<int, int> p = dq.front();
        dq.pop_front();
        for(int i = 0;i < 4;i ++){
            int Nextx = p.first + Direction[i][0];
            int Nexty = p.second + Direction[i][1];
            if(Nextx >= n || Nextx < 0) continue;
            if(Nexty >= m || Nexty < 0) continue;
            if(!vis[Nextx][Nexty] && graph[Nextx][Nexty]){
                vis[Nextx][Nexty] = 1;
                dq.push_back(pair(Nextx, Nexty));
            }
        }
    }
}
#endif
#ifdef DfsWay
int CalculateLandsNumber(vector<vector<int>>& graph){
    int n = graph.size(), m = graph[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int cnt = 0;
    for(int i = 0;i < n;i ++){
        for(int j = 0;j < m;j ++){
            if(!vis[i][j] && graph[i][j]){
                cnt ++;
                vis[i][j] = 1;
                Dfs(graph, vis, i, j);
            }
        }
    }
    return cnt;
}
void Dfs(vector<vector<int>>& graph, vector<vector<int>>& vis, int x, int y){
    for(int i = 0;i < 4;i ++){
        int Nextx = x + Direction[i][0];
        int Nexty = y + Direction[i][1];
        if(Nextx < 0 || Nextx >= n) continue;
        if(Nexty < 0 || Nexty >= m) continue;
        if(!vis[Nextx][Nexty] && graph[Nextx][Nexty]){
            vis[Nextx][Nexty] = 1;
            Dfs(graph, vis, Nextx, Nexty);
        }
    }
}
#endif