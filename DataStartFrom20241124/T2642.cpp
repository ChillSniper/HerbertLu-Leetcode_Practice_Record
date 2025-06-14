#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

class Graph {
public:
    Graph(int n, vector<vector<int>>& edges) {
        for(int i = 0;i < n;i ++){
            for(int j = 0;j < n;j ++){
                G[i][j] = (i == j ? 0 : MAX);
            }
        }
        int m = edges.size();
        for(int i = 0;i < m;i ++){
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            G[u][v] = w;
        }
        for(int i = 0;i < n;i ++){
            for(int j = 0;j < n;j ++){
                D[i][j] = G[i][j];
            }
        }
        for(int k = 0;k < n;k ++){
            for(int i = 0;i < n;i ++){
                for(int j = 0;j < n;j ++){
                    D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
                }
            }
        }
        Num = n;
    }
    
    void addEdge(vector<int> edge) {
        int u = edge[0], v = edge[1], w = edge[2];
        if(w >= D[u][v]) return ;
        for(int i = 0;i < Num;i ++){
            for(int j = 0;j < Num;j ++){
                D[i][j] = min(D[i][j], D[i][u] + w + D[v][j]);
            }
        }
    }
    
    int shortestPath(int node1, int node2) {
        return D[node1][node2] != 0x3f3f3f3f ? D[node1][node2] : -1;
    }
private:
    static const int N = 1e2 + 10, MAX = 0x3f3f3f3f;
    int G[N][N], D[N][N], Num;
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */