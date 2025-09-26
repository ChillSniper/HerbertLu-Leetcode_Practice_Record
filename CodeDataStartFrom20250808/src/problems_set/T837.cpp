#include <bits/stdc++.h>
using namespace std;

#define Test

class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        // 这个题估计是概率dp
        // so crazy.
        // ans = [k, n]
        // Then how to calculate ?
        // enable [0, k - 1]
        // so the maxbound is k - 1 + maxpts
        // the val between [n + 1, k - 1 + maxpts] = 0
        vector<double> dp(k + maxPts, 0);
        // 
        for (int i = k;i <= min(n, k - 1 + maxPts);i ++) {
            dp[i] = 1;
        }
        double tmp = 0;
        for (int i = 1;i <= maxPts;i ++) {
            tmp += dp[k - 1 + i];
        }
        for (int i = k - 1;i >= 0;i --) {
            // (dp[i + 1] + dp[i + 2] + dp[i + maxpts]) / maxpts
            dp[i] = tmp / maxPts;
            tmp -= dp[i + maxPts];
            tmp += dp[i];
        }
        return dp[0];
    }
};

int main() {
    return 0;
}