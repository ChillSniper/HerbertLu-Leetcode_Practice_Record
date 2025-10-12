#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

#define Test

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        bool flag = false;
        int n = board.size(), m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i = 0;i < n;i ++){
            for(int j = 0;j < m;j ++){
                MemsetMatrix(vis);
                flag = Dfs(board, word, 0, vis, i, j);
                if(flag) return flag;
            }
        }        
        return false;
    }
private:
    void MemsetMatrix(vector<vector<int>>& x){
        int n = x.size(), m = x[0].size();
        for(int i = 0;i < n;i ++){
            for(int j = 0;j < m;j ++)
                x[i][j] = 0;
        }
    }
    bool Dfs(vector<vector<char>>& board, string word, int index, vector<vector<int>>& vis, int x, int y){
        bool flag = false;
        int sz = word.size();
        if(index >= sz)
            return true;
        int n = board.size(), m = board[0].size();
        if(word[index] != board[x][y] || vis[x][y])
            return false;
        vis[x][y] = 1;
        if(sz - 1 == index)
            return true;
        for(int i = 0;i < 4;i ++){
            int Nxt_x = x + direciton[i][0], Nxt_y = y + direciton[i][1];
            if(Nxt_x >= 0 && Nxt_x < n && Nxt_y >= 0 && Nxt_y < m && !vis[Nxt_x][Nxt_y]){
                flag = Dfs(board, word, index + 1, vis, Nxt_x, Nxt_y);
                if(flag) return flag;
            }
        }
        vis[x][y] = 0;
        return flag;
    }

    int direciton[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
};

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif

    return 0;
}