#include <bits/stdc++.h>
using namespace std;
#define Test
//#define Way1
#define Way2
class Solution {
public:
    #ifdef Way1
    int climbStairs(int n) {
        int Ans[50];
        Ans[0] = 0; Ans[1] = 1; Ans[2] = 2;
        for(int i = 3;i <= 45;i ++){
            Ans[i] = Ans[i - 1] + Ans[i - 2];
        }
        return Ans[n];
    }
    #endif
    #ifdef Way2
    int climbStairs(int n){
        if(n == 1) return 1;
        int last = 1, current = 2;
        while (n - 2)
        {
            int tmp = last + current;
            last = current;
            current = tmp;
            n -- ;
        }
        return current;
    }
    #endif
};
int main(){
    freopen("file.in", "r", stdin);
    freopen("file.out", "w", stdout);
    int n;
    scanf("%d", &n);
    Solution fk;
    cout << fk.climbStairs(n);
    return 0;
}