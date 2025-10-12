#include <iostream>
#include <cstdio>
#include <vector>
#include <list>
using namespace std;

class Solution{
public:
    void DijkstraAlgorithm(vector<vector<int>>& graph, int n, int u, int pre[], int dis[]){
        int s[N] = {0};
        for(int i = 1;i <= n;i ++){pre[i] = -1; dis[i] = MaxDistance;}
        dis[u] = 0;
        for(int i = 1;i <= n;i ++){
            int v = FindMinVertex(graph, s, dis, n);
            s[v] = 1;
            for(auto j:graph[v]){
                
                if(!s[j] && dis[v] + graph[v][j] < dis[j]){
                    dis[j] = dis[v] + graph[v][j];
                    pre[j] = v;
                }

            }
        }
    }
private:
    int FindMinVertex(vector<vector<int>>& graph, int s[], int dis[], int n){
        int res, MinDistance = MaxDistance;
        for(int i = 1;i <= n;i ++){
            if(!s[i] && dis[i] < MinDistance){
                MinDistance = dis[i];
                res = i;
            }
        }
        return res;
    }
    const int N = 1e5 + 10;
    const int MaxDistance = 0x3f3f3f3f;
};