#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define Test
//#define Print
int n, m;
int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
unordered_map<int, int> mp;
void MarkGraph(vector<vector<int>>& graph, vector<vector<int>>& vis);
int Dfs(vector<vector<int>>& graph, vector<vector<int>>& vis, int markNum, int x, int y);
int AfterChangeMaxArea(vector<vector<int>>& graph, vector<vector<int>>& vis);
int main(){
    #ifdef Test
    freopen("file.in", "r", stdin);
    freopen("file.out", "w", stdout);
    #endif
    scanf("%d%d", &n, &m);
    vector<vector<int>> graph(n, vector<int>(m, 0));
    for(int i = 0;i < n;i ++)
        for(int j = 0;j < m;j ++)
            scanf("%d", &graph[i][j]);
    vector<vector<int>> vis(n, vector<int>(m, 0));   
    MarkGraph(graph, vis);
    #ifdef Print
    for(int i = 0;i < n;i ++){
        for(int j = 0;j < m;j ++)
            printf("%d ", graph[i][j]);
        printf("\n");
    }
    #endif
    printf("%d", AfterChangeMaxArea(graph, vis));
    return 0;
}
void MarkGraph(vector<vector<int>>& graph, vector<vector<int>>& vis){
    int mark = 2;
    for(int i = 0;i < n;i ++){
        for(int j = 0;j < m;j ++){
            if(graph[i][j] == 1 && !vis[i][j]){
                mp[mark] = Dfs(graph, vis, mark, i, j);
                mark ++;
            }
        }
    }
}
int Dfs(vector<vector<int>>& graph, vector<vector<int>>& vis, int mark, int x, int y){
    vis[x][y] = 1;
    graph[x][y] = mark;
    int sum = 1;
    for(int i = 0;i < 4;i ++){
        int Nextx = x + dir[i][0];
        int Nexty = y + dir[i][1];
        if(Nextx >= n || Nextx < 0 || Nexty >= m || Nexty < 0) continue;
        if(graph[Nextx][Nexty] && !vis[Nextx][Nexty])
            sum += Dfs(graph, vis, mark, Nextx, Nexty);
    }
    return sum;
}
int AfterChangeMaxArea(vector<vector<int>>& graph, vector<vector<int>>& vis){
    int MaxArea = 0;
    for(auto item : mp)
        MaxArea = max(MaxArea, item.second);
    for(int i = 0;i < n;i ++){
        for(int j = 0;j < m;j ++){
            if(!vis[i][j] && !graph[i][j]){
                int currentArea = 1;
                unordered_set<int> st;
                for(int k = 0;k < 4;k ++){
                    int Nexti = i + dir[k][0];
                    int Nextj = j + dir[k][1];
                    if(Nexti >= n || Nexti < 0 || Nextj >= m || Nextj < 0) continue;
                    if(graph[Nexti][Nextj] && !st.count(graph[Nexti][Nextj])){
                        currentArea += mp[graph[Nexti][Nextj]];
                        st.insert(graph[Nexti][Nextj]);
                    }
                }
                MaxArea = max(MaxArea, currentArea);
            }
        }
    }
    return MaxArea;
}