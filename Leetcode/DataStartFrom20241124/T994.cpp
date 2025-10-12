#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define Test
// #define OriginalWay
#define BetterWay
typedef pair<int, int> pr;
const int INF = 0x3f3f3f3f;
#ifdef BetterWay
// 优化版的思路是
// 对于多源广度优先搜索问题，可以先将源点放入队列中，即等价于 这些源点从一个原始源点扩展而来
class Solution {
    public:
        int orangesRotting(vector<vector<int>>& grid) {
            int n = grid.size(), m = grid[0].size();
            deque<pr> dq;
            vector<vector<int>> Time(n, vector<int>(m, INF)), vis(n, vector<int>(m, 0));
            for(int i = 0;i < n;i ++){
                for(int j = 0;j < m;j ++){
                    if(grid[i][j] == 2){
                        dq.push_back(make_pair(i, j));
                    }
                }
            }
            int t = 0;
            while (dq.size())
            {
                int sz = dq.size();
                t ++;
                for(int i = 0;i < sz;i ++){
                    pr f = dq.front();
                    dq.pop_front();
                    int x = f.first, y = f.second;
                    if(!vis[x][y]){
                        vis[x][y] = 1;
                        for(int j = 0;j < 4;j ++){
                            int Nxt_x = x + direction[j][0], Nxt_y = y + direction[j][1];
                            if(Nxt_x >= 0 && Nxt_x < n && Nxt_y >= 0 && Nxt_y < m && !vis[Nxt_x][Nxt_y] && grid[Nxt_x][Nxt_y] == 1){
                                Time[Nxt_x][Nxt_y] = min(Time[Nxt_x][Nxt_y], t);
                                dq.push_back(make_pair(Nxt_x, Nxt_y));
                            }
                        }
                    }
                }
            }
            int res = 0, flag = 0;
            for(int i = 0;i < n;i ++){
                for(int j = 0;j < m;j ++){
                    if(Time[i][j] != INF){
                        res = max(res, Time[i][j]);
                    }
                    if(Time[i][j] == INF && grid[i][j] == 1)
                        flag = 1;
            }
            }
            if(flag)
                return -1;
            return res;
        }
    private:
        int direction[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
    };
#endif
#ifdef OriginalWay
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> Time(n, vector<int>(m, INF)), vis(n, vector<int>(m, 0));
        deque<pair<int, int>> dq;
        for(int i = 0;i < n;i ++){
            for(int j = 0;j < m;j ++){
                // if(grid[i][j] == '')
                // 这道题思路很乱 大致就是采用广度优先搜索 然后直到队列为空为止
                // 但是存在几个问题 可能会导致时间复杂度大大增加
                // 但是可以先试一下思路
                if(grid[i][j] == 2){
                    SetZeroOfGrid(vis);
                    dq.push_back(make_pair(i, j));
                    int t = 0;
                    while (dq.size())
                    {
                        int sz = dq.size();
                        t ++;
                        for(int i = 0;i < sz;i ++){
                            pr f = dq.front();
                            dq.pop_front();
                            int x = f.first, y = f.second;
                            if(!vis[x][y]){
                                vis[x][y] = 1;
                                for(int j = 0;j < 4;j ++){
                                    int Nxt_x = x + direction[j][0], Nxt_y = y + direction[j][1];
                                    if(Nxt_x >= 0 && Nxt_x < n && Nxt_y >= 0 && Nxt_y < m && !vis[Nxt_x][Nxt_y] && grid[Nxt_x][Nxt_y] == 1){
                                        Time[Nxt_x][Nxt_y] = min(Time[Nxt_x][Nxt_y], t);
                                        dq.push_back(make_pair(Nxt_x, Nxt_y));
                                    }
                                }
                            }
                        }
                    }
                    
                }
            }
        }
        int res = 0, flag = 0;
        for(int i = 0;i < n;i ++){
            for(int j = 0;j < m;j ++){
                if(Time[i][j] != INF){
                    res = max(res, Time[i][j]);
                }
                if(Time[i][j] == INF && grid[i][j] == 1)
                    flag = 1;
            }
        }
        if(flag)
            return -1;
        return res;
    }
private:

    void SetZeroOfGrid(vector<vector<int>>& grid){
        int n = grid.size(), m = grid[0].size();
        for(int i = 0;i < n;i ++)
            for(int j = 0;j < m;j ++)
                grid[i][j] = 0;
    }
    int direction[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
};
#endif
int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    vector<vector<int>> T = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    Solution s;
    s.orangesRotting(T);
    return 0;
}