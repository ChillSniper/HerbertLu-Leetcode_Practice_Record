#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        int Lx, Ly;
        Lx = Ly = 0;
        int cnt = 1;
        int Length = n;
        while (Lx < n / 2)
        {
            for(int j = Ly;j < Length - 1;j ++) ans[Lx][j] = cnt ++;
            for(int i = Lx;i < Length - 1;i ++) ans[i][Length - 1] = cnt ++;
            for(int j = Length - 1;j > Ly;j --) ans[Length - 1][j] = cnt ++;
            for(int i = Length - 1;i > Lx;i --) ans[i][Ly] = cnt ++;

            Lx ++;
            Ly ++;
            Length --;
        }
        if(n % 2) ans[n / 2][n / 2] = cnt;
        return ans;
    }
};

int main(){

    return 0;
}