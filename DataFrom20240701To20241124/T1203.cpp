#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <list>
using namespace std;
class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        vector<vector<int>> GroupItem(n + m);
        for(int i = 0;i < n;i ++){
            if(group[i] == -1) group[i] = m ++;
            GroupItem[group[i]].push_back(i);
        }
        
        vector<int> GroupId(m);
        for(int i = 0;i < m;i ++) GroupId[i] = i;

        vector<list<int>> GraphOfGroup(m);
        vector<list<int>> GraphOfItem(n);
        vector<int> InDegreeOfGroup(m, 0);
        vector<int> InDegreeOfItem(n, 0);
  
        for(int i = 0;i < beforeItems.size();i ++){
            int currentGroup = group[i];
            for(int j = 0;j < beforeItems[i].size();j ++){
                int BeforeGroup = group[beforeItems[i][j]];
                if(BeforeGroup == currentGroup){
                    GraphOfItem[beforeItems[i][j]].push_back(i);
                    InDegreeOfItem[i] ++;
                } else{
                    GraphOfGroup[BeforeGroup].push_back(currentGroup);
                    InDegreeOfGroup[currentGroup] ++;
                }
            }
        }

        vector<int> TopoGroup = TopoSort(GraphOfGroup, GroupId, InDegreeOfGroup);
        if(!TopoGroup.size()) return {};
        
        vector<int> ans;
        for(int i = 0;i < m;i ++){
            int currentGroup = TopoGroup[i];
            vector<int> res = TopoSort(GraphOfItem, GroupItem[currentGroup], InDegreeOfItem);
            if(res.size() != GroupItem[currentGroup].size()) return {};
            for(int j = 0;j < res.size();j ++) ans.push_back(res[j]);
        }
        return ans;
    }
private:
    vector<int> TopoSort(vector<list<int>>& graph, vector<int>& items, vector<int>& Indegree){
        vector<int> res;
        stack<int> st;
        for(auto item:items){
            if(!Indegree[item]) st.push(item);
        }
        for(int i = 0;i < items.size();i ++){
            if(st.empty()) return {};
            int k = st.top(); st.pop();
            res.push_back(k);
            for(auto j:graph[k]){
                if(-- Indegree[j] == 0) st.push(j);
            }
        }
        return res;
    }
};
int main(){
    return 0;
}