#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define Test
const int N = 5e2 + 10, M = N * 10;
struct Edge
{
    int to, Nxt, w;
};
const int Max = 0x3f3f3f3f;
int Head[N], idx, n, m, vis[N], dis[N], pre[N];
Edge e[M];
void AddEdge(int u, int v, int w);
int Dijkstra();
int findMinDistance();
int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    memset(Head, -1, sizeof(Head));
    scanf("%d%d", &n, &m);
    for(int i = 0;i < m;i ++){
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        AddEdge(u, v, w);
    }
    printf("%d", Dijkstra());
    return 0;
}
void AddEdge(int u, int v, int w){
    e[idx].to = v;
    e[idx].Nxt = Head[u];
    e[idx].w = w;
    Head[u] = idx ++;
}
int Dijkstra(){
    for(int i = 1;i <= n;i ++){
        dis[i] = Max; pre[i] = -1;
    }
    int ans = 0, u;
    dis[1] = 0;
    for(int i = 1;i <= n;i ++){
        u = findMinDistance();
        vis[u] = 1;
        for(int j = Head[u];j != -1;j = e[j].Nxt){
            int v = e[j].to;
            if(!vis[v] && dis[v] > dis[u] + e[j].w){
                dis[v] = dis[u] + e[j].w;
                pre[v] = u;
            }
        }
    }
    return dis[n] != Max ? dis[n] : -1;
}
int findMinDistance(){
    int res = -1, Min = Max;
    for(int i = 1;i <= n;i ++){
        if(!vis[i] && dis[i] < Min){
            Min = dis[i];
            res = i;
        }
    }
    return res;
}