#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> graph(numCourses);
        vector<vector<bool>> record(numCourses, vector<bool>(numCourses, false));
        vector<bool> ans;
        vector<int> Indegree(numCourses, 0);
        int n = prerequisites.size();
        for(int i = 0;i < n;i ++){
            int u = prerequisites[i][0], v = prerequisites[i][1];
            graph[u].push_back(v);
            Indegree[v] ++;
        }
        deque<int> dq;
        for(int i = 0;i < numCourses;i ++){
            if(Indegree[i] == 0) dq.push_back(i);
        }
        while (!dq.empty())
        {
            int u = dq.front(); dq.pop_front();
            int sz = graph[u].size();
            for(int i = 0;i < sz;i ++){
                int v = graph[u][i];
                record[u][v] = true;
                for(int i = 0;i < numCourses;i ++){
                    record[i][v] = record[i][v] || record[i][u];
                }
                if(--Indegree[v] == 0) dq.push_back(v);
            }
        }
        int sz = queries.size();
        for(int i = 0;i < sz;i ++){
            int u = queries[i][0], v = queries[i][1];
            if(record[u][v]) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};