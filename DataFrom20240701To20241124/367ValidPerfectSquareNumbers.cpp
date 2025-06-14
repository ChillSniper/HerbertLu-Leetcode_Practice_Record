#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        double x0 = num, x1 = num;
        while (1)
        {
            x0 = 0.5 * (x1 + (double)num / x1);
            if(fabs(x1 - x0) < 1e-7) break;
            x1 = x0;
        }
        if((int) x1 * int (x1) == num) return true;
        else return false;
    }
};

int main(){
    freopen("file.in", "r", stdin);
    freopen("file.out",  "w", stdout);
    int x;
    cin >> x;
    Solution s;
    if(s.isPerfectSquare(x)) printf("true");
    else printf("false");
    return 0;
}