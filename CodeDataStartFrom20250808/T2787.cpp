#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
#define Test

typedef long long ll;
const int MOD = 1e9 + 7;
class Solution {
public:
    int numberOfWays(int n, int x) {
        // 这道题得想到转化成为0-1背包问题 ...
        // 我真麻了，这道题还是之前刷过的，第二遍写的时候还是一点都没思路
        vector<ll> f(n + 1, 0);
        f[0] = 1;
        for(int i = 1; pow(i, x) <= n; ++i) {
            int val = pow(i, x);
            for(int j = n;j >= val;j --) {
                f[j] = (f[j] + f[j - val]) % MOD;
            }
        }
        return f[n] % MOD;
    }
};

int main() {
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif

    return 0;
}