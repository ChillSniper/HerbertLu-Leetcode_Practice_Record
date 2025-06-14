#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
using namespace std;
#define Test
int n, m, dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
void Dfs(vector<vector<int>>& graph, vector<vector<int>>& vis, int x, int y);
int main(){
    #ifdef Test
    freopen("file.in", "r", stdin);
    freopen("file.out", "w", stdout);
    #endif
    // ����ĺ�������������������
    // 1.��θ�Ч�Ľ�ͼ
    // 2.��α���ͼ
    // �Լ����ܷ�̬����ͼ��
    scanf("%d%d", &n, &m);
    vector<vector<int>> ans;
    vector<vector<int>> graph(n, vector<int>(m, 0));
    for(int i = 0;i < n;i ++)
        for(int j = 0;j < m;j ++)
            scanf("%d", &graph[i][j]);
    vector<vector<int>> Pacific(n, vector<int>(m, 0));
    vector<vector<int>> Atlantic = Pacific;
    for(int i = 0;i < n;i ++){
        Dfs(graph, Pacific, i, 0);
        Dfs(graph, Atlantic, i, m - 1);
    }
    for(int j = 0;j < m;j ++){
        Dfs(graph, Pacific, 0, j);
        Dfs(graph, Atlantic, n - 1, j);
    }
    for(int i = 0;i < n;i ++){
        for(int j = 0;j < m;j ++){
            if(Pacific[i][j] && Atlantic[i][j]){
                ans.push_back({i, j});
            }
        }
    }
    for(int i = 0;i < ans.size();i ++){
        printf("%d %d\n", ans[i][0], ans[i][1]);
    }
    return 0;
}
void Dfs(vector<vector<int>>& graph, vector<vector<int>>& vis, int x, int y){
    vis[x][y] = 1;
    for(int i = 0;i < 4;i ++){
        int nextx = x + dir[i][0];
        int nexty = y + dir[i][1];
        if(nextx >= n || nextx < 0) continue;
        if(nexty >= m || nexty < 0) continue;
        if(!vis[nextx][nexty] && graph[nextx][nexty] >= graph[x][y]){
            vis[nextx][nexty] = 1;
            Dfs(graph, vis, nextx, nexty);
        }
    }
}