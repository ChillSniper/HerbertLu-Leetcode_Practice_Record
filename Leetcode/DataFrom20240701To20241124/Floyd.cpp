#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
#define Test
const int N = 1e3 + 10;
void Floyd(vector<vector<int>>& graph, vector<vector<int>>& D, vector<vector<int>>& path);
void PrintPath(vector<vector<int>>& path, int a, int b);
int main(){
    return 0;
}
void Floyd(vector<vector<int>>& graph, vector<vector<int>>& D, vector<vector<int>>& path){
    int n = graph.size() - 1;
    // Init();
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= n;j ++){
            D[i][j] = graph[i][j];
            if(i != j && graph[i][j]) path[i][j] = j;
            else path[i][j] = -1;
        }
    }
    // dynamic planning
    for(int k = 1;k <= n;k ++){
        for(int i = 1;i <= n;i ++){
            for(int j = 1;j <= n;j ++){
                if(D[i][k] + D[k][j] < D[i][j]){
                    D[i][j] = D[i][k] + D[k][j];
                    path[i][j] = path[i][k];
                }
            }
        }
    }
}
void PrintPath(vector<vector<int>>& path, int a, int b){
    for(int k = a;k != b;k = path[k][b]){
        printf("%d", path[k][b]);
    }
}