#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <math.h>
#include <queue>
using namespace std;
// Prim Algorithm

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size(), index = 0, ans = 0;
        priority_queue<P> p;
        for(int i = 0;i < n;i ++) dis[i] = INF;
        dis[0] = 0;
        p.push(P{0, 0});
        while (!p.empty())
        {
            P tmp = p.top(); p.pop();
            int u = tmp.u, w = tmp.w;
            if(!vis[u]){
                vis[u] = 1;
                ans += w;
                for(int i = 0;i < n;i ++){
                    if(!vis[i] && abs(points[u][0] - points[i][0]) + abs(points[u][1] - points[i][1]) < dis[i]){
                        dis[i] = abs(points[u][0] - points[i][0]) + abs(points[u][1] - points[i][1]);
                    }
                    if(!vis[i]){
                        p.push(P{i, dis[i]});
                    }
                }
            }
        }
        return ans;
    }
private:
    static const int N = 1e3 + 10, INF = 0x3f3f3f3f;
    int vis[N], dis[N];
    struct Info
    {
        int x, y;
    };
    struct P{
        int u, w;
        bool operator < (const P& x) const{
            return x.w < this->w;
        }
    };
};

int main(){
    return 0;
}