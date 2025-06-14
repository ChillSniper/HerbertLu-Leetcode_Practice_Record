#include <bits/stdc++.h>
using namespace std;
#define Test

class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int sz = edges.size();
        vector<int> Indegree(sz, 0), vis(sz, 0);
        for(int i = 0;i < sz;i ++){
            if(edges[i] != -1){
                Indegree[edges[i]] ++;
            }
        }
        deque<int> dq;
        for(int i = 0;i < sz;i ++){
            if(Indegree[i] == 0){
                dq.push_back(i);
            }
        }
        while (dq.size())
        {
            int dqsz = dq.size();
            for(int i = 0;i < dqsz;i ++){
                int p = dq.front(); dq.pop_front();
                if(!vis[p]){
                    vis[p] = 1;
                    int q = edges[p];
                    if(q != -1 && --Indegree[q] == 0){
                        dq.push_back(q);
                    }
                }
            }
        }
        for(int i = 0;i < sz;i ++){
            if(!vis[i]){
                CrossTheCircle(edges, vis, i);
            }
        }
        return ans;
    }
private:
    int ans = 0;
    void CrossTheCircle(vector<int>& edges, vector<int>& vis, int i){
        int t = 0;
        while (vis[i] == 0)
        {
            vis[i] = 1;
            i = edges[i];
            t ++;
        }
        ans = max(ans, t);
    }
};

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    vector edges = {2, -1, 3, 1};
    Solution t;
    cout << t.longestCycle(edges);
    return 0;
}