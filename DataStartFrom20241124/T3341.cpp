#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<int>> dis(n, vector<int>(m, Max));
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int i = 0, j = 0;
        dis[i][j] = 0;
        P tmp = P(0, 0, dis[i][j]);
        priority_queue<P> p;
        p.push(tmp);
        while (i != n - 1 || j != m - 1)
        {
            P tmp = p.top(); p.pop();
            i = tmp.x;
            j = tmp.y;
            if(!vis[i][j]){
                vis[i][j] = 1;
                for(int k = 0;k < 4;k ++){
                    int Nxtx = i + dir[k][0];
                    int Nxty = j + dir[k][1];
                    if(Nxtx >= 0 && Nxtx < n && Nxty >= 0 && Nxty < m && !vis[Nxtx][Nxty]){
                        dis[Nxtx][Nxty] = min(dis[Nxtx][Nxty], max(dis[i][j], moveTime[Nxtx][Nxty]) + 1);
                        P tmp = P(Nxtx, Nxty, dis[Nxtx][Nxty]);
                        p.push(tmp);
                    }
                }
            }
        }
        return dis[n - 1][m - 1];
    }
    struct P
    {
        int x, y, Time;
        bool operator < (const P& x)const{
            return x.Time < this->Time;
        }
        P(int a, int b, int t): x(a), y(b), Time(t){};
    };
    int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
    const int Max = 0x3f3f3f3f;
};

int main(){
    vector<vector<int>> graph = {{0, 0, 0}, {0, 0, 0}};
    Solution s;
    s.minTimeToReach(graph);
    return 0;
}