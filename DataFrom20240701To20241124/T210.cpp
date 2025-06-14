#include <iostream>
#include <cstdio>
#include <stack>
#include <list>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<list<int>> graph(numCourses);
        vector<int> ans;
        for(int i = 0;i < prerequisites.size();i ++)
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        int Indegree[3000] = {0};
        GetIndegree(graph, numCourses, Indegree);
        stack<int> st;
        for(int i = 0;i < numCourses;i ++) if(!Indegree[i]) st.push(i);
        for(int i = 0;i < numCourses;i ++){
            if(st.empty()) return {};
            int k = st.top(); st.pop();
            ans.push_back(k);
            for(auto j:graph[k]){
                Indegree[j] --;
                if(!Indegree[j]) st.push(j);
            }
        }
        return ans;
    }
private:
    void GetIndegree(vector<list<int>>& graph, int n, int InDegree[]){
        for(int i = 0;i < n;i ++) InDegree[i] = 0;
        for(int i = 0;i < n;i ++){
            for(auto j:graph[i]) InDegree[j] ++;
        }
    }
};
int main(){
    return 0;
}