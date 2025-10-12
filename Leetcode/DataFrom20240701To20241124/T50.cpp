#include <bits/stdc++.h>
using namespace std;
//#define Way1
#define Way2

class Solution {
public:
    #ifdef Way1
    double myPow(double x, int n){
        if(n == 0 || x == 1) return 1;
        if(n == 1) return x;
        if(n == -1) return 1.0 / x;
        double result;
        double Pre = myPow(x, n / 2);
        result = Pre * Pre;
        if(n % 2) result *= x;
        return result;
    }
    #endif
    #ifdef Way2
    double myPow(double x, int n){
        if(n < 0) return 1.0 / myPow(x, -(n + 1)) / x; 
        double res = 1.0;
        double x_use = x;
        while (n > 0)
        {
            if(n % 2) res *= x_use;
            n /= 2;
            x_use = x_use * x_use;
        }
        return res;
    }
    #endif
};

int main(){
    freopen("file.in", "r", stdin);
    freopen("file.out", "w", stdout);
    Solution s;
    cout << s.myPow(2, -3);
    return 0;
}