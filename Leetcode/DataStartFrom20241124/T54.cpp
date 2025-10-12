#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define Test

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), INF = 0x3f3f3f3f;
        int x = 0, y = 0, sum = m * n, direction[4][2] = {0, 1, 1, 0, 0, -1, -1, 0}, dir = 0;
        vector<int> ans;
        for(int cnt = 0;cnt < sum;){
            if(x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] != INF){
                ans.push_back(matrix[x][y]);
                matrix[x][y] = INF;
                cnt ++;
            } 
            int Nxt_x = x + direction[dir][0];
            int Nxt_y = y + direction[dir][1];
            if(Nxt_x >= 0 && Nxt_x < m && Nxt_y >= 0 && Nxt_y < n && matrix[Nxt_x][Nxt_y] != INF){
                x = Nxt_x;
                y = Nxt_y;
            } else{
                dir = (dir + 1) % 4;
                x = x + direction[dir][0];
                y = y + direction[dir][1];
            }
        }    
        return ans;  
    }
};

int main(){
    return 0;
}