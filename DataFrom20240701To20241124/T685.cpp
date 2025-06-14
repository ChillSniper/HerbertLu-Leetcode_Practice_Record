#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int N = 1e5 + 10, M = 10 * N;
int idx, Head[N];
struct Edge
{
    int to;
    int weight;
    int Next;
};
Edge edge[M];
class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        memset(Father, -1, sizeof(Father));
        int n = edges.size();
        for(int i = 0;i < n;i ++){
            int u = edges[i][0], v = edges[i][1];
            AddEdge(v, u);
            Indegree[v] ++;
        }
        int res = -1;
        for(int i = 1;i <= n;i ++){
            if(Indegree[i] == 2){
                res = i;
                break;
            }
        }
        if(res != -1){
            int index = head[res];
            if(IsTree(res, index, edges)) return {edge[index].to, res};
            index = edge[index].Next;
            return {edge[index].to, res};
        } else FindTheCircle(edges);
        return ans;
    }
private:
    vector<int> ans;
    static const int N = 1e3 + 10;
    struct Edge
    {
        int to;
        int Next;
    };
    Edge edge[N];
    int Father[N], Rank[N], head[N], idx, Indegree[N] = {0};
    void Init(int n){
        for(int i = 1;i <= n;i ++)
            Father[i] = i, Rank[i] = 0;
    }
    int FindFather(int x){
        if(Father[x] == x) return x;
        Father[x] = FindFather(Father[x]);
        return Father[x];
    }
    void Union(int x, int y){
        int fx = FindFather(x), fy = FindFather(y);
        if(fx == fy) return ;
        if(Rank[fx] > Rank[fy])
            Father[fy] = fx;
        else{
            if(Rank[fx] == Rank[fy]) Rank[fy] ++;
            Father[fx] = fy;
        }
    }
    bool IsSameRoot(int x, int y){
        int fx = FindFather(x), fy = FindFather(y);
        return fx == fy;
    }
    void AddEdge(int a, int b){
        edge[idx].to = b;
        edge[idx].Next = head[a];
        head[a] = idx ++;
    }
    bool IsTree(int v, int index, vector<vector<int>>& edges){
        int u = edge[index].to, n = edges.size(); 
        Init(n);
        for(int i = 0;i < n;i ++){
            int st = edges[i][0], fin = edges[i][1];
            if(st == u && fin == v) continue;
            if(IsSameRoot(st, fin)) return false;
            Union(st, fin);
        }
        return true;
    }
    void FindTheCircle(vector<vector<int>>& edges){
        int n = edges.size();
        Init(n);
        for(int i = 0;i < n;i ++){
            int u = edges[i][0], v = edges[i][1];
            if(IsSameRoot(u, v)){
                ans = {u, v};
                return ;
            }
            Union(u, v);
        }
    }
};