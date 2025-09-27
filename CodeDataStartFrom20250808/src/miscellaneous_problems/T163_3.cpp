#include <bits/stdc++.h>
using namespace std;

#define Test

const int N = 5e4 + 10, M = 2e5 + 10, INF = 0x3f3f3f3f;
int Head[N], vis[N], Nxt[M], To[M], idx = 0, cost[M], Path[N];
typedef pair<int, int> pr;

class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        memset(Head, -1, sizeof Head);
        idx = 0;
        memset(vis, 0, sizeof vis);
        for (auto& item : edges) {
            int u = item[0], v = item[1], w = item[2];
            AddEdge(u, v, w);
            AddEdge(v, u, 2 * w);
        }
        memset(Path, 0x3f, sizeof Path);
        priority_queue<pr, vector<pr>, greater<pr>> pq;
        Path[0] = 0;
        pq.push({0, 0});
        while (int(pq.size()))
        {
            pr tmp = pq.top();
            pq.pop();
            int u = tmp.second;
            if(u == n - 1) {
                break;
            }
            if(vis[u]) {
                continue;
            }
            vis[u] = 1;
            for (int i = Head[u];i != -1;i = Nxt[i]) {
                int v = To[i];
                if(Path[v] > Path[u] + cost[i]) {
                    Path[v] = Path[u] + cost[i];
                    pq.push({Path[v], v});
                }
            }
        }
        return Path[n - 1] >= INF / 2 ? -1 : Path[n - 1];
    }
private:
    void AddEdge(int u, int v, int w) {
        To[idx] = v;
        Nxt[idx] = Head[u];
        cost[idx] = w;
        Head[u] = idx ++;
    }
};

int main() {
    return 0;
}