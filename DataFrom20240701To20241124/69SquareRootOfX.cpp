#include <iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x;
        while (l <= r)
        {
            long long mid = (l + r) / 2;
            if(mid * mid < (long long)x){
                l = mid + 1;
            }else if(mid * mid > (long long)x){
                r = mid - 1;
            }else if(mid * mid == (long long)x){
                return (int)mid;
            }
        }
        return r;
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