#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
#define Test
const int N = 1e2 + 10, M = 2e3 + 10;
int idx, head[N], vis[N], n, m;
struct Edge
{
    int to;
    int nxt;
};
Edge edge[M];
void AddEdge(int a, int b);
void Dfs(int a);
int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    memset(head, -1, sizeof(head));
    scanf("%d%d", &n, &m);
    for(int i = 0;i < m;i ++){
        int a, b;
        scanf("%d%d", &a, &b);
        AddEdge(a, b);
    }
    vis[1] = 1;
    Dfs(1);
    for(int i = 1;i <= n;i ++){
        if(!vis[i]){printf("-1"); return 0;}
    }
    printf("1");
    return 0;
}
void AddEdge(int a, int b){
    edge[idx].nxt = head[a];
    edge[idx].to = b;
    head[a] = idx ++;
}
void Dfs(int a){
    for(int i = head[a];i != -1;i = edge[i].nxt){
        int j = edge[i].to;
        if(!vis[j]){
            vis[j] = 1;
            Dfs(j);
        }
    }
}