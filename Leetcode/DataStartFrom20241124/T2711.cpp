#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;
#define Test

class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 0));
        vector<vector<int>> pre = ans, suf = ans;
        for(int i = 0;i < n;i ++){
            int x = i, y = 0;
            unordered_set<int> st;
            while (x < n && y < m)
            {
                if(!st.count(grid[x][y]))
                    st.insert(grid[x][y]);
                pre[x][y] = (int)st.size();
                x ++;
                y ++;
            }
        } 
        for(int j = 1;j < m;j ++){
            int x = 0, y = j;
            unordered_set<int> st;
            while (x < n && y < m)
            {
                if(!st.count(grid[x][y]))
                    st.insert(grid[x][y]);
                pre[x][y] = (int)st.size();
                x ++;
                y ++;
            }
        }
        for(int i = 0;i < n;i ++){
            int x = i, y = m - 1;
            unordered_set<int> st;
            while (x >= 0 && y >= 0)
            {
                if(!st.count(grid[x][y]))
                    st.insert(grid[x][y]);
                suf[x][y] = (int)st.size();
                x --;
                y --;
            }
        }
        for(int j = 1;j < m;j ++){
            int x = n - 1, y = j;
            unordered_set<int> st;
            while (x >= 0 && y >= 0)
            {
                if(!st.count(grid[x][y]))
                    st.insert(grid[x][y]);
                suf[x][y] = (int)st.size();
                x --;
                y --;
            }
        }
        for(int i = 0;i < n;i ++){
            for(int j = 0;j < m;j ++){
                int x = i - 1 >= 0 && j - 1 >= 0 ? pre[i - 1][j - 1] : 0;
                int y = i + 1 < n && j + 1 < m ? suf[i + 1][j + 1] : 0;
                ans[i][j] = abs(x - y);
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