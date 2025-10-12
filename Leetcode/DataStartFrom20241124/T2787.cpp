#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;
class Solution {
public:
    int numberOfWays(int n, int x) {
        vector<int> f(n + 1, 0);
        int s = 0;
        for(int i = 1;i <= n;i ++){
            if(i >= 20 && x >= 2)
                break;
            int tlim = (int) pow(i, x);
            s += tlim;
            for(int j = min(s, n);j >= 0;j --){
                f[j] = (f[j] + f[j - tlim]) % (int)(1e9 + 7);
            }
        }
        return f[n];
    }
};