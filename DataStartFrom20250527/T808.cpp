#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

#define Test

class Solution {
public:
    double soupServings(int n) {
        if (n >= (int)1e4) {
            return 1.0;
        }
        n = (n + 24) / 25;
        vector<vector<double>> memo(n + 1, vector<double>(n + 1, -1));
        double ans = Dfs(n, n, memo);

        return ans;
    }
private: 
    double Dfs(int a, int b, vector<vector<double>>& memo) {
        if(a <= 0 && b <= 0) {
            return 0.5;
        }
        if (a <= 0 && b > 0) {
            return 1;
        }
        if (a > 0 && b <= 0) {
            return 0;
        }
        if (memo[a][b] != -1) {
            return memo[a][b];
        }
        memo[a][b] = (Dfs(a - 4, b, memo) + Dfs(a - 3, b - 1, memo) 
        + Dfs(a - 2, b - 2, memo) + Dfs(a - 1, b - 3, memo)) / 4;
        return memo[a][b];
    }
};

int main() {
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    return 0;
}