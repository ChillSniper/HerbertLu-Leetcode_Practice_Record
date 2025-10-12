#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

#define Test

const int INF = 1e7;
class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size(), ans = 0;
        for (int i = 0;i < n;i ++) {
            ans += fruits[i][i];
            fruits[i][i] = -INF;
        }      
        for (int i = 0;i < n - 1;i ++) {
            fruits[i][0] = fruits[0][i] = -INF;
        }
        fruits[n - 1][n - 1] = 0;
        for (int i = 1;i < n;i ++) {
            for (int j = n - 1;j >= i;j --) {
                int extra = j == n - 1 ? 0 : fruits[i - 1][j + 1];
                fruits[i][j] += max(extra, max(fruits[i - 1][j], fruits[i - 1][j - 1]));
                extra = j == n - 1 ? 0 : fruits[j + 1][i - 1];
                fruits[j][i] += max(extra, max(fruits[j][i - 1], fruits[j - 1][i - 1]));
            } 
        }
        return ans + fruits[n - 1][n - 1];
    }
};

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    return 0;
}