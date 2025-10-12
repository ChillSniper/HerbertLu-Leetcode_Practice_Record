#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define Test
struct Edge
{
    int u, v, w;
};
const int N = 1e4 + 10, M = N * 10;
Edge e[N];
int F[N], n, m, R[N];
void Init();
int FindFather(int x);
void Union(int x, int y);
bool cmp(Edge a, Edge b);
int Kruskal();
int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    scanf("%d%d", &n, &m);
    for(int i = 0;i < m;i ++) scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
    printf("%d", Kruskal());
    return 0;
}
void Init(){
    for(int i = 1;i <= n;i ++) F[i] = i;
}
int FindFather(int x){
    if(F[x] == x) return x;
    F[x] = FindFather(F[x]);
    return F[x];
}
bool cmp(Edge a, Edge b){
    return a.w < b.w;
}
void Union(int x, int y){
    int fx = FindFather(x), fy = FindFather(y);
    if(fx == fy) return ;
    if(R[fx] > R[fy]) F[fy] = fx;
    else {
        if(R[fx] == R[fy]) R[fy] ++;
        F[fx] = fy;
    }
}
int Kruskal(){
    Init();
    sort(e, e + m, cmp);
    int cnt = 0, ans = 0;
    for(int i = 0;i < m;i ++){
        int u = e[i].u, v = e[i].v;
        if(FindFather(u) == FindFather(v)) continue;
        Union(u, v);
        ans += e[i].w;
        if(++ cnt == n - 1) break;
    }
    return ans;
}