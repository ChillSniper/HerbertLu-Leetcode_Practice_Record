#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

#define Test

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> graph(n, vector<int>(n, 0));
        Dfs(graph, 0, 0, 1, n);
        return ans;
    }
private:
    vector<vector<string>> ans;
    void Dfs(vector<vector<int>>& graph, int x, int y, int index, int n){
        if(index > n){
            int sz = graph.size();
            vector<string> x;
            for(int i = 0;i < sz;i ++){
                string s;
                for(int j = 0;j < sz;j ++){
                    if(graph[i][j])
                        s += 'Q';
                    else 
                        s += '.';
                }
                x.push_back(s);
            }
            ans.push_back(x);
            return ;
        }
        if(x >= n || y >= n)
            return ;
        for(int j = y;j < n;j ++){
            if(Check(graph, x, j)){
                graph[x][j] = 1;
                Dfs(graph, x, j, index + 1, n);
                graph[x][j] = 0;
            }
        }
    }
    bool Check(vector<vector<int>>& graph, int x, int y){
        int n = graph.size();
        for(int j = 0;j < y;j ++){
            if(graph[x][j])
                return false;
        }
        for(int i = 0;i < x;i ++){
            if(graph[i][y])
                return false;
        }
        int st_x = x - 1, st_y = y - 1;
        while (st_x >= 0 && st_y >= 0 && st_x < n && st_y < n)
        {
            if(graph[st_x][st_y])
                return false;
            -- st_x;
            -- st_y;
        }
        st_x = x - 1;
        st_y = y + 1;
        while (st_x >= 0 && st_y >= 0 && st_x < n && st_y < n)
        {
            if(graph[st_x][st_y])
                return false;
            -- st_x;
            ++ st_y;
        }
        return true;
    }
};

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    Solution s;
    s.solveNQueens(4);
    return 0;
}