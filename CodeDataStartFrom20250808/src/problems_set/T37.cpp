#include <bits/stdc++.h>
using namespace std;
#define Test

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        
        vector<set<char>> collection(BOARD_SIZE * BOARD_SIZE);
        // set<char> collection[BOARD_SIZE * BOARD_SIZE];
        map<int, int> pq;
        for (int i = 0;i < BOARD_SIZE;i ++) {
            for (int j = 0;j < BOARD_SIZE;j ++) {
                if (board[i][j] == '.') {
                    Update(board, collection, pq, i, j);
                }
            }
        }
        bool flag = false;
        Dfs(board, flag, collection, pq);
    }
private:
    const int BOARD_SIZE = 9;

    void Update(vector<vector<char>>& board, vector<set<char>>& collection, 
        map<int, int>& pq, int x, int y) {
        int Index = x * BOARD_SIZE + y;
        collection[Index].clear();
        set<char> flag;
        int st_x = (x / 3) * 3;
        int st_y = (y / 3) * 3;
        for (int i = 0;i < BOARD_SIZE;i ++) {
            if(board[i][y] != '.') {
                flag.insert(board[i][y]);
            }
        }
        for (int j = 0;j < BOARD_SIZE;j ++) {
            if(board[x][j] != '.') {
                flag.insert(board[x][j]);
            }
        }
        for (int i = st_x;i < st_x + 3;i ++) {
            for (int j = st_y;j < st_y + 3;j ++) {
                if (board[i][j] != '.') {
                    flag.insert(board[i][j]);
                }
            }
        }
        for (int i = 1;i <= 9;i ++) {
            char ch = (i + '0');
            if(!flag.count(ch)) {
                collection[Index].insert(ch);
            }
        }
        pq[Index] = collection[Index].size();
    }

    void Dfs(vector<vector<char>>& board, bool& IsFinished, vector<set<char>>& collection, 
        map<int, int>& pq) {
        if(IsFinished) {
            return ;
        }
        if(pq.empty()) {
            cout << "fuck" << endl;
            IsFinished = true;
            return ;
        }
        int Choose_Index = -1, val = 10;
        for (auto item : pq) {
            if (item.second < val) {
                val = item.second;
                Choose_Index = item.first;
            }
        }
        pq.erase(Choose_Index);

        int row = Choose_Index / BOARD_SIZE;
        int col = Choose_Index % BOARD_SIZE;

        Update(board, collection, pq, row, col);

        auto ori_collect = collection; 
        auto ori_pq = pq;

        for (auto item : collection[Choose_Index]) {
            board[row][col] = item;

            if(!IsFinished)
                Dfs(board, IsFinished, collection, pq);

            board[row][col] = '.';
            collection = ori_collect;
            pq = ori_pq;
        }
    }
    
};

int main() {
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    char ch = '0' + 1;
    cout << ch;
    return 0;
}