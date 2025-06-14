#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 1e3 + 10;
int Father[N], Rank[N];
#define Test
void Init(int n);
int FindFather(int x);
void Union(int x, int y);
bool Judge(int x, int y);
int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    int n;
    scanf("%d", &n);
    Init(n);
    for(int i = 0;i < n;i ++){
        int a, b;
        scanf("%d%d", &a, &b);
        if(Judge(a, b)){
            printf("%d %d", a, b);
            return 0;
        }
        Union(a, b);
    }
    return 0;
}
void Init(int n){
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
    if(Rank[fx] > Rank[fy])
        Father[fy] = fx;
    else{
        if(Rank[fx] == Rank[fy])
            Rank[fy] ++;
        Father[fx] = fy;
    }
}
bool Judge(int x, int y){
    int fx = FindFather(x), fy = FindFather(y);
    return fx == fy ? true : false; 
}