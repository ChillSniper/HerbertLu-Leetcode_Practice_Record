#include <iostream>
#include <cstdio>
#include <vector>
#include <list>
using namespace std;
#define Test
//#define AdjacentMatrixWay
#define AdjacentListWay
#ifdef AdjacentListWay
vector<vector<int>> result;
void DFS(vector<int>& tmp, int k, int n, vector<list<int>>& graph);
int main(){
    #ifdef Test
    freopen("file.in", "r", stdin);
    freopen("file.out", "w", stdout);
    #endif
    int n, m;
    scanf("%d%d", &n, &m);
    vector<list<int>> graph(n + 1);
    while (m --)
    {
        int s, t;
        scanf("%d%d", &s, &t);
        graph[s].push_back(t);
    }
    vector<int> tmp;
    tmp.push_back(1);
    DFS(tmp, 1, n, graph);
    for(int i = 0;i < result.size();i ++){
        if(i) printf("\n");
        for(int j = 0;j < result[i].size();j ++){
            if(j) printf(" ");
            printf("%d", result[i][j]);
        }
    }
    if(!result.size()) printf("-1");
    return 0;
}
void DFS(vector<int>& tmp, int k, int n, vector<list<int>>& graph){
    if(k == n){
        result.push_back(tmp);
        return;
    }
    for(auto i:graph[k]){
        tmp.push_back(i);
        DFS(tmp, i, n, graph);
        tmp.pop_back();
    }
}
#endif

#ifdef AdjacentMatrixWay
vector<vector<int>> result;
void DFS(vector<vector<int>>& graph, int k, int n, vector<int>& tmp);
int main(){
    #ifdef Test
    freopen("file.in", "r", stdin);
    freopen("file.out", "w", stdout);
    #endif 
    int n, m;
    scanf("%d%d", &n, &m);
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, 0));
    while (m --)
    {
        int s, t;
        scanf("%d%d", &s, &t);
        graph[s][t] = 1;
    }
    vector<int> tmp;
    tmp.push_back(1);
    DFS(graph, 1, n, tmp);
    for(int i = 0;i < result.size();i ++){
        if(i) printf("\n");
        for(int j = 0;j < result[i].size();j ++){
            if(j) printf(" ");
            printf("%d", result[i][j]);
        }
    }
    // pay attention to the special situation
    if(!result.size()) printf("-1");
    return 0;
}
void DFS(vector<vector<int>>& graph, int k, int n, vector<int>& tmp){
    if(k == n){
        result.push_back(tmp);
        return;
    }
    for(int i = 1;i <= n;i ++){
        if(graph[k][i]){
            tmp.push_back(i);
            DFS(graph, i, n, tmp);
            tmp.pop_back();
        } 
    }
}
#endif