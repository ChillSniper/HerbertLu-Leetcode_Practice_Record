#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return 0;
        double x1 = x, xi = x;
        while (1)
        {
            xi = 0.5*(x1 + (double)x / x1);
            if(fabs(x1 - xi) < 1e-7) break;
            x1 = xi;
        }
        return (int)x1;
    }
};
int main(){
    freopen("file.in", "r", stdin);
    freopen("file.out", "w", stdout);
    int x;
    cin >> x;
    Solution s;
    int result = s.mySqrt(x);
    std::cout << result;
    return 0;
}