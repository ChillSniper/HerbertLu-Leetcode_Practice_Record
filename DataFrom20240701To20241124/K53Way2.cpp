#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define Test
const int N = 1e4 + 10, M = N * 10, INF = 0x3f3f3f3f;
int idx, n, m, vis[N], dis[N], Head[N];
struct Edge
{
    int to, weight, Nxt;
};
Edge e[M];
void AddEdge(int u, int v, int w);
int Prim();
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
        AddEdge(v, u, w);
    }
    printf("%d", Prim());
    return 0;
}
void AddEdge(int u, int v, int w){
    e[idx].to = v;
    e[idx].weight = w;
    e[idx].Nxt = Head[u];
    Head[u] = idx ++;
}
int Prim(){
    int cur = 1, ans = 0, cnt = 0;
    for(int i = 1;i <= n;i ++) dis[i] = INF;
    dis[1] = 0;
    for(int i = Head[cur];i != -1;i = e[i].Nxt){
        int v = e[i].to;
        if(dis[v] > e[i].weight)
            dis[v] = e[i].weight;
    }
    while (++ cnt < n)
    {
        vis[cur] = 1;
        int Min = INF;
        for(int i = 1;i <= n;i ++){
            if(!vis[i] && dis[i] < Min){
                Min = dis[i]; cur = i;
            }
        }
        ans += Min;
        for(int i = Head[cur];i != -1;i = e[i].Nxt){
            int v = e[i].to;
            if(!vis[v] && dis[v] > e[i].weight){
                dis[v] = e[i].weight;
            }
        }
    }
    return ans;
}