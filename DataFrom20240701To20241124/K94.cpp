#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define Test
struct Edge{
    int to, w, Nxt;
};
const int N = 1e3 + 10, M = 1e4 + 10, INF = 0x3f3f3f3f;
int Head[N], idx, Dis[N], n, m;
Edge e[M];
void AddEdge(int u, int v, int w);
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
    for(int i = 1;i <= n;i ++) Dis[i] = INF;
    Dis[1] = 0;
    for(int i = 0;i < n;i ++){
        for(int j = 1;j <= n;j ++){
            for(int k = Head[j];k != -1;k = e[k].Nxt){
                int v = e[k].to;
                if(Dis[j] != INF && Dis[v] > Dis[j] + e[k].w){
                    Dis[v] = Dis[j] + e[k].w;
                }
            }
        }
    }
    if(Dis[n] == INF) printf("unconnected");
    else printf("%d", Dis[n]);
    return 0;
}
void AddEdge(int u, int v, int w){
    e[idx].to = v;
    e[idx].w = w;
    e[idx].Nxt = Head[u];
    Head[u] = idx ++;
}