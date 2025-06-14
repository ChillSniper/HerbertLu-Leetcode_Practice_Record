#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define Test

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0)); 
        int direction[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
        int pos_i = 0, pos_j = 0, dir = 0;
        for(int i = 1;i <= n * n;i ++){
            ans[pos_i][pos_j] = i;
            int Nxt_i = pos_i + direction[dir][0], Nxt_j = pos_j + direction[dir][1];
            if(Nxt_i >= 0 && Nxt_i < n && Nxt_j >= 0 && Nxt_j < n && !ans[Nxt_i][Nxt_j]){
                pos_i = Nxt_i; pos_j = Nxt_j;
            } else{
                dir = (dir + 1) % 4;
                pos_i = pos_i + direction[dir][0];
                pos_j = pos_j + direction[dir][1];
            }
        }
        return ans;
    }
};

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif

    return 0;
}