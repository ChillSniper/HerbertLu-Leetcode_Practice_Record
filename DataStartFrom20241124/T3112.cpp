#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        memset(Head, -1, sizeof(Head));
        idx = 0;
        ans = vector<int>(n, -1);
        int sz = edges.size();
        for(int i = 0;i < sz;i ++){
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            AddEdge(u, v, w);
            AddEdge(v, u, w);
        }
        Dijkstra(n, disappear);
        return ans;
    }
private:
    static const int INF = 0x3f3f3f3f, N = 5e4 + 10, M = 1e5 + 10;
    int Head[N], vis[N], dis[N], idx;
    vector<int> ans;
    int Dijkstra(int n, vector<int>& disappear){
        for(int i = 0;i < n;i ++){
            dis[i] = INF;
            vis[i] = 0;
        }
        priority_queue<P> p;
        dis[0] = 0;
        p.push(P{0, 0});
        while (!p.empty())
        {
            P tmp = p.top(); p.pop();
            int u = tmp.u;
            if(!vis[u]){
                vis[u] = 1;
                ans[u] = (dis[u] < disappear[u]) ? dis[u] : -1;
                for(int i = Head[u];i != - 1;i = e[i].Nxt){
                    int v = e[i].to;
                    if(!vis[v] && dis[v] > dis[u] + e[i].w && dis[u] + e[i].w < disappear[v]){
                        dis[v] = dis[u] + e[i].w;
                    }
                    if(!vis[v]) p.push(P{v, dis[v]});
                }
            }
        }
        return -1;        
    }
    struct Edge
    {
        int to, Nxt, w;
    };
    Edge e[M * 2];
    void AddEdge(int u, int v, int w){
        e[idx].to = v;
        e[idx].Nxt = Head[u];
        e[idx].w = w;
        Head[u] = idx ++;
    }
    struct P
    {
        int u, w;
        bool operator < (const P& x)const{
            return x.w < this->w;
        }
    };
    
};

int main(){

    return 0;
}