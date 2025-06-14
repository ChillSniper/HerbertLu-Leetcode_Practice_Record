#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

void WarShall(vector<vector<int>>& graph, int n, vector<vector<int>>& R);
int main(){
    return 0;
}
void WarShall(vector<vector<int>>& graph, int n, vector<vector<int>>& R){
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= n;j ++){
            R[i][j] = graph[i][j];
        }
    }
    for(int k = 1;k <= n;k ++){
        for(int i = 1;i <= n;i ++){
            for(int j = 1;j <= n;j ++){
                R[i][j] = R[i][j] || (R[i][k] && R[k][j]);
            }
        }
    }
}