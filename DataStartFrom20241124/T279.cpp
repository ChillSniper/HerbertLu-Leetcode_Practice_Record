#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define Test
const int N = 1e4 + 10;
class Solution {
    public:
        int numSquares(int n) {
            // f[i - j * j] + 1
            vector<int> f(n + 1, 0);
            const int INF = 0x3f3f3f3f;
            for(int i = 1;i <= n;i ++){
                int Min = INF;
                for(int j = 1;j * j <= i;j ++){
                    Min = min(Min, f[i - j * j]);
                }
                f[i] = Min + 1;
            }
            return f[n];
        }
    private:
};
int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    int n = 12;
    Solution s;
    cout << s.numSquares(n);
    return 0;
}