#include <bits/stdc++.h>
using namespace std;

#define Test

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, int> cnt;
        for (int i = 0;i < 9;i ++) {
            cnt.clear();
            for (int j = 0;j < 9;j ++) {
                if(board[i][j] != '.') {
                    int p = board[i][j] - '0';
                    if(cnt.count(p))
                        return false;
                    cnt[p] ++;
                }
            }
        }
        for (int i = 0;i < 9;i ++) {
            cnt.clear();
            for (int j = 0;j < 9;j ++) {
                if(board[j][i] != '.') {
                    int p = board[j][i] - '0';
                    if(cnt.count(p))
                        return false;
                    cnt[p] ++;
                }
            }
        }
        for (int st = 0;st < 9;st += 3) {
            for (int fk = 0;fk < 9;fk += 3) {
                cnt.clear();
                for (int i = st;i < st + 3;i ++) {
                    for (int j = fk;j < fk + 3;j ++) {
                        if(board[i][j] != '.') {
                            int p = board[i][j] - '0';
                            if(cnt.count(p))
                                return false;
                            cnt[p] ++;
                        }
                    }
                }
            }
        }
        return true;
    }
};

int main() {
    #ifdef Test
    #endif
    return 0;
}