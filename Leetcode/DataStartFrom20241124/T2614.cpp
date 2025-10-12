#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define Test
class Solution {
public:
    int diagonalPrime(vector<vector<int>>& nums) {
        int n = nums.size();
        int MaxPrime = 0;
        for(int i = 0;i < n;i ++){
            int a = nums[i][i], b = nums[i][n - i - 1];
            if(IsPrime(a))
                MaxPrime = max(MaxPrime, a);
            if(IsPrime(b))
                MaxPrime = max(MaxPrime, b);
        }
        return MaxPrime;
    }
    bool IsPrime(int n){
        if(n <= 1)
            return false;
        for(int i = 2;i <= n / i;i ++){
            if(n % i == 0)
                return false;
        }
        return true;
    }
};
int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif

    return 0;
}