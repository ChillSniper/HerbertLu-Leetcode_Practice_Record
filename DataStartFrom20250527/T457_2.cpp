#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
#define Test
// 这题不如一开始初始化建边之后，对每个点统计过去一个连通集，然后直接用unordered<int, set<int>>存储

const int N = 1e5 + 10;
int Downline[N], BelongMinist[N];
int idx, Head[N], To[N * 2], Nxt[N * 2], vis[N];
class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        unordered_map<int, set<int>> ump;
        unordered_map<int, int> FindSet;
        memset(Head, -1, sizeof Head);
        memset(To, 0, sizeof To);
        memset(Downline, 0, sizeof Downline);
        idx = 0;
        memset(vis, 0, sizeof vis);
        for(auto item : connections){
            int u = item[0], v = item[1];
            AddEdge(u, v);
            AddEdge(v, u);
        }
        for(int i = 1;i <= c;i ++){
            if(vis[i]){
                continue;
            }
            // vis[i] = 1;
            deque<int> dq;
            set<int>& store = ump[i];
            store.insert(i);
            dq.push_back(i);
            FindSet[i] = i;
            while (dq.size())
            {
                int u = dq.front();
                dq.pop_front();
                if(vis[u]){
                    continue;
                }
                vis[u] = 1;
                for(int j = Head[u];j != -1;j = Nxt[j]){
                    int v = To[j];
                    if(!vis[v]){
                        dq.push_back(v);
                        store.insert(v);
                        FindSet[v] = i;
                    }
                }
            }
            
        }
        vector<int> ans;
        for(auto item : queries){
            int tp = item[0], x = item[1];
            if(tp == 1){
                if(Downline[x] == 0){
                    ans.push_back(x);
                }
                else{
                    int SetIndex = FindSet[x];
                    auto& tmp_set = ump[SetIndex];
                    if(tmp_set.size() == 0){
                        ans.push_back(-1);
                    }
                    else{
                        ans.push_back(*tmp_set.begin());
                    }
                }
            }
            else if(tp == 2){
                Downline[x] = 1;
                int SetIndex = FindSet[x];
                auto& tmp_set = ump[SetIndex];
                if(tmp_set.count(x)){
                    tmp_set.erase(x);
                }
            }
        }
        return ans;
    }
private:
    void AddEdge(int u, int v){
        Nxt[idx] = Head[u];
        To[idx] = v;
        Head[u] = idx ++;
    }
};
int main(){
    return 0;
}