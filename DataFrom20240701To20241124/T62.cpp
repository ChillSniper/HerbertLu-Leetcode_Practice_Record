#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
//#define Way1
#define Way2
using namespace std;
#define Test

class Solution {
public:
    #ifdef Way1
    int uniquePaths(int m, int n) {
        int Ans[200] = {0};
        for(int i = 1;i <= n;i ++)
            Ans[i] = 1;
        for(int i = 2;i <= m;i ++){
            for(int j = 1;j <= n;j ++){
                Ans[j] = Ans[j] + Ans[j - 1];
            }
        }
        return Ans[n];
    }
    #endif
    #ifdef Way2
    int uniquePaths(int m, int n){
        return C(n + m - 2, m - 1);
    }
    #endif
private:
    long long C(int n, int k){
        long long res = 1;
        if(k > n / 2) k = n - k;
        for(int i = 1;i <= k;i ++)
            res = res * (n - k + i) / i;
        return res;
    }
};

int main(){
    #ifdef Test
    freopen("file.in", "r", stdin);
    freopen("file.out", "w", stdout);
    #endif
    int m, n;
    scanf("%d%d", &m, &n);
    Solution s;
    cout << s.uniquePaths(m, n);
    return 0;
}