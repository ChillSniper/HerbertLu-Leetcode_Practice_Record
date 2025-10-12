#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <list>
using namespace std;
#define Test

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> Indegree(numCourses, 0), vis(numCourses, 0);
        vector<list<int>> graph(numCourses);
        int sz = prerequisites.size();
        for(int i = 0;i < sz;i ++){
            int u = prerequisites[i][0], v = prerequisites[i][1];
            graph[u].push_back(v);
            Indegree[v] ++;
        }
        deque<int> dq;
        for(int i = 0;i < numCourses;i ++){
            if(Indegree[i] == 0)
                dq.push_back(i);
        }
        int cnt = 0;
        while (dq.size())
        {
            int u = dq.front(); dq.pop_front();
            if(!vis[u]){
                vis[u] = 1;
                ++ cnt;
                for(auto v : graph[u]){
                    if(--Indegree[v] == 0)
                        dq.push_back(v);
                }
            }
        }
        return cnt == numCourses;
    }
};

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    Solution s;
    vector<vector<int>> k = {{1, 0}};
    s.canFinish(2, k);
    return 0;
}