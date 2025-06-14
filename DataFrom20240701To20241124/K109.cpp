#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
#define Test
struct Edge
{
    int to;
    int Next;
};
void AddEdge(int a, int b);
const int N = 1e3 + 10;
int Head[N], idx, Indegree[N], Father[N], Rank[N];
Edge edge[N];
void FindTheCircle(vector<vector<int>>& store);
void Init(int n);
int FindFather(int x);
void Union(int x, int y);
bool IsSameRoot(int x, int y);
bool IsTree(int v, int index, vector<vector<int>>& store);
int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    int n, res = -1;
    scanf("%d", &n);
    vector<vector<int>> store;
    for(int i = 1;i <= n;i ++){
        int s, t;
        scanf("%d%d", &s, &t);
        Indegree[t] ++;
        AddEdge(t, s);
        // add the edge s->t
        // but 
        store.push_back({s, t});
    }
    for(int i = 1;i <= n;i ++){
        if(Indegree[i] == 2){
            res = i;
            break;
        }
    }
    if(res != -1){
        int index = Head[res];
        if(IsTree(res, index, store)){
            printf("%d %d", edge[index].to, res);
            return 0;
        }
        index = edge[index].Next;
        printf("%d %d", edge[index].to, res);
        return 0;
    } else FindTheCircle(store);
    return 0;
}
void AddEdge(int a, int b){
    edge[idx].to = b;
    edge[idx].Next = Head[a];
    Head[a] = idx ++;
}
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
    else {
        if(Rank[fx] == Rank[fy])
            Rank[fy] ++;
        Father[fx] = fy;
    }
}
bool IsSameRoot(int x, int y){
    int fx = FindFather(x);
    int fy = FindFather(y);
    return fx == fy;
}
bool IsTree(int v, int index, vector<vector<int>>& store){
    int u = edge[index].to, n = store.size();
    Init(n);
    for(int i = 0;i < n;i ++){
        int st = store[i][0], fin = store[i][1];
        if(st == u && fin == v) continue;
        if(IsSameRoot(st, fin)){
            return false;
        }
        Union(st,fin);
    }
    return true;
}
void FindTheCircle(vector<vector<int>>& store){
    int n = store.size();
    Init(n);
    for(int i = 0;i < n;i ++){
        int u = store[i][0], v = store[i][1];
        if(IsSameRoot(u, v)){
            printf("%d %d", u, v);
            return;
        }
        Union(u, v);
    }
}