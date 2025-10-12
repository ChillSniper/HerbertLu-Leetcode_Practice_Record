#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        n_all = n;
        int m = roads.size();
        memset(Head, -1, sizeof(Head));
        for(int i = 0;i < m;i ++){
            AddEdge(roads[i][0], roads[i][1], roads[i][2]);
            AddEdge(roads[i][1], roads[i][0], roads[i][2]);
        }
        Dijkstra(0, n - 1);
    }
private:
    struct Edge
    {
        int to, Nxt, w;
    };
    static const int N = 2e2 + 10, M = N * N, INF = 0x3f3f3f3f;
    int Head[N], vis[N], dis[N], idx, n_all;
    Edge e[M];
    typedef pair<int, int> pr;
    
    priority_queue<pr> p;
    void AddEdge(int u, int v, int w){
        e[idx].to = v;
        e[idx].Nxt = Head[u];
        e[idx].w = w;
        Head[u] = idx ++;
    }
    void Dijkstra(int st, int fin){
        for(int i = 0;i < n_all;i ++) dis[i] = INF;
        dis[st] = 0;
        p.push(make_pair(st, 0));
        for (int i = 0;i < n_all;i ++)
        {
            
        }
        
    }
};