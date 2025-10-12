#include <iostream>
#include <cstdio>
#include <vector>
#include <list>
#include <stack>
using namespace std;
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<list<int>> graph(numCourses);
        for(int i = 0;i < prerequisites.size();i ++)
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        int Indegree[3000] = {0};
        GetIndegree(graph, numCourses, Indegree);
        stack<int> st;
        for(int i = 0;i < numCourses;i ++) if(!Indegree[i]) st.push(i);
        for(int i = 0;i < numCourses;i ++){
            if(st.empty()) return false;
            int k = st.top(); st.pop();
            for(auto j:graph[k]){
                Indegree[j] --;
                if(!Indegree[j]) st.push(j);
            }
        }
        return true;
    }
private:
    void GetIndegree(vector<list<int>>& graph, int n, int InDegree[]){
        for(int i = 0;i < n;i ++) InDegree[i] = 0;
        for(int i = 0;i < n;i ++){
            for(auto j:graph[i]) InDegree[j] ++;
        }
    }
};
#define Test
int main(){
    #ifdef Test
    freopen("file.in", "r", stdin);
    freopen("file.out", "w", stdout);
    #endif

    return 0;
}