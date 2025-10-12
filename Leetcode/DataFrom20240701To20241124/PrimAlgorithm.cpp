#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1e3 + 10;
const int INF = 0x3f3f3f3f;
int Prim(int G[N][N], int n);
int FindMin(int* vis, int* dis, int n);
int main(){
    return 0;
}
int Prim(int G[N][N], int n){
    int Pre[N], vis[N] = {0}, dis[N], ans = 0;
    for(int i = 1;i <= n;i ++){
        Pre[i] = -1;
        dis[i] = INF;
    }
    dis[1] = 0;
    for(int i = 1;i <= n;i ++){
        int u = FindMin(vis, dis, n);
        // pay attention to the serious situation
        if(u == -1) return ans;
        // Operation here
        vis[u] = 1;
        ans += dis[u];
        for(int j = 1;j <= n;j ++){
            if(!vis[j] && G[u][j] < dis[j]){
                dis[j] = G[u][j];
                Pre[j] = u;
            }
        }
    }
    return ans;
}
int FindMin(int* vis, int* dis, int n){
    int Min = INF, res = -1;
    for(int i = 1;i <= n;i ++){
        if(!vis[i] && dis[i] < Min){
            Min = dis[i];
            res = i;
        }
    }
    return res;
}