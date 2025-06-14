#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        memset(Head, -1, sizeof(Head));
        memset(vis, 0, sizeof(vis));
        nn = n; m = times.size();
        for(int i = 0;i < times.size();i ++){
            int u = times[i][0], v = times[i][1], w = times[i][2];
            AddEdge(u, v, w);
        }
        return Dijkstra(k);
    }
    int Dijkstra(int k){
        for(int i = 1;i <= nn;i ++) Path[i] = INF;
        Path[k] = 0;
        int u;
        for(int i = 1;i <= nn;i ++){
            u = FindMinPath();
            if(u == -1) return -1;
            vis[u] = 1;
            for(int j = Head[u];j != -1;j = e[j].Nxt){
                int v = e[j].to;
                if(!vis[v] && Path[v] > Path[u] + e[j].w)
                    Path[v] = Path[u] + e[j].w;
            }
        }
        return Path[u];
    }
    int FindMinPath(){
        int res = -1, Min = INF;
        for(int i = 1;i <= nn;i ++){
            if(!vis[i] && Path[i] < Min){
                Min = Path[i];
                res = i;
            }
        }
        return res;
    }
private:
    static const int N = 110, M = 6010, INF = 0x3f3f3f3f;
    int nn, m;
    struct Edge
    {
        int to, w, Nxt;
    };
    Edge e[M];
    int Head[N], idx, vis[N], Path[N];
    void AddEdge(int u, int v, int w){
        e[idx].to = v;
        e[idx].w = w;
        e[idx].Nxt = Head[u];
        Head[u] = idx ++;
    }
};
int main(){
    return 0;
}