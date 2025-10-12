#include <bits/stdc++.h>
using namespace std;
#define Test
const int N = 1e5 + 10;
const int INF = 0x3f3f3f3f;
int idx, vis[N], Nxt[N], Head[N], dis[N], st[N], ed[N], To[N];
class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
        idx = 0;
        memset(Head, -1, sizeof Head);
        memset(vis, 0, sizeof vis);
        memset(dis, 0x3f, sizeof dis);
        memset(To, 0, sizeof To);
        dis[0] = 0;
        vis[0] = 1;
        int sz = edges.size();
        for(int i = 0;i < sz;i ++){
            int u_i = edges[i][0], v_i = edges[i][1], st_i = edges[i][2], end_i = edges[i][3];
            Nxt[idx] = Head[u_i];
            st[idx] = st_i;
            ed[idx] = end_i;
            To[idx] = v_i;
            Head[u_i] = idx ++;
        }
        deque<int> dq;
        dq.push_back(0);
        while ((int)dq.size())
        {
            int u = dq.front(); dq.pop_front();
            for(int i = Head[u];i != -1;i = Nxt[i]){
                int v = To[i];
                int target_u = dis[u] >= st[i] ? dis[u] + 1 : st[i] + 1;
                if((!vis[v] && ed[i] >= dis[u]) || (vis[v] && ed[i] >= dis[u] && target_u < dis[v])){
                    vis[v] = 1;
                    dis[v] = target_u;
                    dq.push_back(v);
                }
            }
        }
        return dis[n - 1] == INF ? -1 : dis[n - 1];
    }
};
int main(){
    return 0;
}