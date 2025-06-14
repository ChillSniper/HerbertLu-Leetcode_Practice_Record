#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
#define Test
//#define PrintDiary
struct Edge
{
    int to, w, nxt;
};
struct Priority
{
    int id, w;
    bool operator <(const Priority& x)const{
        return x.w < this->w;
    }
};
priority_queue<Priority> p;
const int N = 5e2 + 10, M = N * 10, INF = 0x3f3f3f3f;
int vis[N], Head[N], idx, n, m, Path[N];
Edge e[M];
void AddEdge(int u, int v, int w);
int Dijkstra();
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
    #ifdef PrintDiary
    for(int i = 1;i <= n;i ++){
        printf("Path[%d] : %d\n", i, Path[i]);
    }
    #endif
    return 0;
}
void AddEdge(int u, int v, int w){
    e[idx].w = w;
    e[idx].to = v;
    e[idx].nxt = Head[u];
    Head[u] = idx ++;
}
int Dijkstra(){
    for(int i = 1;i <= n;i ++)
        Path[i] = INF;
    Path[1] = 0;
    p.push(Priority{1, Path[1]});
    while(!p.empty()){
        Priority tmp = p.top(); p.pop();
        int u = tmp.id;
        if(!vis[u]){
            vis[u] = 1;
            Path[u] = tmp.w;
            #ifdef PrintDiary
                printf("Result : %d has the shortest length path[%d]:%d\n", u, u, Path[u]);
            #endif
            for(int j = Head[u];j != -1;j = e[j].nxt){
                int v = e[j].to;
                #ifdef PrintDiary
                    printf("Test: %d is in comparision path[%d]: %d  ans vis[%d] : %d\n", v, v, Path[v], v, vis[v]);
                #endif
                if(!vis[v] && Path[v] > Path[u] + e[j].w){
                    Path[v] = Path[u] + e[j].w;
                    #ifdef PrintDiary
                        printf("Change Test : Path[%d]:%d\n", v, Path[v]);
                    #endif
                }
                if(!vis[v])
                    p.push(Priority{v, Path[v]});
            }
        }
    }
    return Path[n] != INF ? Path[n] : -1;
}