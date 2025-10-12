#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
using namespace std;
#define Test

typedef pair<int, int> pr;
int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for(int i = 0;i < m;i ++){
            for(int j = 0;j < n;j ++){
                if(vis[i][j]){
                    continue;
                }
                if(board[i][j] == 'X'){
                    vis[i][j] = 1;
                    continue;
                }
                // get all the f**king linear block.
                vis[i][j] = 1;
                deque<pr> dq;
                vector<pr> store;
                dq.push_back(make_pair(i, j));
                while (dq.size())
                {
                    pr f = dq.front(); dq.pop_front();
                    int cur_x = f.first;
                    int cur_y = f.second;
                    store.push_back(make_pair(cur_x, cur_y));
                    for(int i = 0;i < 4;i ++){
                        int nxt_x = cur_x + dir[i][0];
                        int nxt_y = cur_y + dir[i][1];
                        if(nxt_x < 0 || nxt_x >= m || nxt_y < 0 || nxt_y >= n){
                            continue;
                        }
                        if(vis[nxt_x][nxt_y]){
                            continue;
                        }
                        if(board[nxt_x][nxt_y] == 'O'){
                            dq.push_back(make_pair(nxt_x, nxt_y));
                            vis[nxt_x][nxt_y] = 1;
                        }
                    }
                }
                int flag = true;
                for(int i = 0;i < store.size();i ++){
                    pr cur = store[i];
                    int x = cur.first;
                    int y = cur.second;
                    for(int j = 0;j < 4;j ++){
                        int nxt_x = x + dir[j][0];
                        int nxt_y = y + dir[j][1];
                        if(nxt_x < 0 || nxt_x >= m || nxt_y < 0 || nxt_y >= n){
                            flag = false;
                            goto A;
                        }
                    }
                }
                A:
                if(flag){
                    for(auto item : store){
                        int x = item.first;
                        int y = item.second;
                        board[x][y] = 'X';
                    }
                }
            }
        }
    }
};

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    return 0;
}