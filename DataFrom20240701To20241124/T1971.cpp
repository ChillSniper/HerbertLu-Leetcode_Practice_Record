#include <iostream>
#include <cstdio>
#include <vector>
#include <list>
#include <queue>
using namespace std;
#define UnionWay
//#define BfsWay
//#define DfsWay
#define Test
#ifdef UnionWay
class Union{
public:
    void MakeSet(int n){
        father = vector<int>(n, 0);
        rank = vector<int>(n, 0);
        for(int i = 0;i < n;i ++) father[i] = i;
    }
    int FindFather(int x){
        if(x != father[x]){
            father[x] = FindFather(father[x]);
        }
        return father[x];
    }
    void UnionTwoSet(int x, int y){
        int fx = FindFather(x), fy = FindFather(y);
        if(fx == fy) return;
        if(rank[fx] > rank[fy]){
            father[fy] = fx;
        } else{
            father[fx] = fy;
            if(rank[fx] == rank[fy]) rank[fy] ++;
        }
    }
    bool JudgeTwoPoint(int x, int y){
        return FindFather(x) == FindFather(y);
    }
private:
    vector<int> father;
    vector<int> rank;
};
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        Union u;
        u.MakeSet(n);
        for(auto edge:edges){
            u.UnionTwoSet(edge[0], edge[1]);
        }
        return u.JudgeTwoPoint(source, destination);
    }
};
#endif
#ifdef DfsWay
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<list<int>> graph(n);
        vector<int> visited(n, 0);
        for(auto edge:edges){
            graph[edge[0]].push_back(edge[1]); graph[edge[1]].push_back(edge[0]);
        }
        return Dfs(graph, visited, source, destination);
    }
    bool Dfs(vector<list<int>>& graph, vector<int>& visited, int source, int destination){
        visited[source] = 1;
        if(source == destination) return true;
        for(auto p:graph[source]){
            if(!visited[p] && Dfs(graph, visited, p, destination)) return true;
        }
        return false;
    }
};
#endif
#ifdef BfsWay
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<list<int>> graph(n);
        vector<int> visited(n, 0);
        for(auto edge:edges){
            graph[edge[0]].push_back(edge[1]); graph[edge[1]].push_back(edge[0]);
        }
        queue<int> q;
        q.push(source);
        visited[source] = 1;
        while (!q.empty())
        {
            int k = q.front(); q.pop();
            if(k == destination) return true;
            for(auto i:graph[k]){
                if(!visited[i]) q.push(i), visited[i] = 1;
            }
        }
        return false;
    }
};
#endif
int main(){
    #ifdef Test
    freopen("file.in", "r", stdin);
    freopen("file.out", "w", stdout);
    #endif
    return 0;
}