#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define Test
struct Edge
{
    int head;
    int tail;
    int weight;
};
const int N = 1e3 + 10;
int Father[N], Rank[N];
bool cmp(Edge* a, Edge* b);
void Unit(int n);
int FindFather(int x);
void Union(int x, int y);
int KruskalAlgorithm(Edge* E[], int n, int e);
int main(){
    return 0;
}
bool cmp(Edge* a, Edge* b){
    return a->weight < b->weight;
}
void Unit(int n){
    for(int i = 1;i <= n;i ++) Father[i] = i;
}
int FindFather(int x){
    if(Father[x] == x) return x;
    Father[x] = FindFather(Father[x]);
    return Father[x];
}
void Union(int x, int y){
    int fx = FindFather(x), fy = FindFather(y);
    if(fx == fy) return ;
    if(Rank[fx] > Rank[fy]){
        Father[fy] = fx;
    } else{
        if(Rank[fx] == Rank[fy]) Rank[fy] ++;
        Father[fx] = fy;
    }
}
int KruskalAlgorithm(Edge* E[], int n, int e){
    Unit(n);
    sort(E, E + e, cmp);
    int ans = 0, k = 0;
    for(int i = 0;i < e;i ++){
        int u = E[i]->head, v = E[i]->tail, w = E[i]->weight;
        if(FindFather(u) != FindFather(v)){
            k ++;
            ans += w;
            // Related Operation
            // ...
            Union(u, v);
        }
        if(k  == n - 1) return ans;
    }
    return -1;
}