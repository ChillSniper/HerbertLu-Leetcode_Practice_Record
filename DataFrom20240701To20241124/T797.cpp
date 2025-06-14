#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> tmp;
        int n = graph.size();
        DFS(tmp, graph, 0, n);
        return result;
    }
private:
    void DFS(vector<int>& tmp, vector<vector<int>>& graph, int k, int n){
        if(k == n - 1){
            result.push_back(tmp);
            return;
        }
        for(int i = 0;i < graph[k].size();i ++){
            tmp.push_back(graph[k][i]);
            DFS(tmp, graph, graph[k][i], n);
            tmp.pop_back();
        }
    }
    vector<vector<int>> result;
};