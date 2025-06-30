#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
#define Test

const int MOD = 1e9 + 7;
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int cnt = 0, sz = nums.size();
        int l = 0, r = sz - 1;
        while (l <= r)
        {
            int t = nums[l] + nums[r];
            if(t > target){
                -- r;
            }  
            else{
                cnt = (cnt + ((int)MyPow(2, r - l)) % MOD) % MOD;
                ++ l;
            }
        }
        return cnt;
    }
private: 
    int MyPow(int p, int q){
        if(q == 1){
            return p % MOD;
        }
        int res = 1;
        int t = MyPow(p, q / 2) % MOD;
        res = t * t % MOD;
        if(q % 2){
            res = (res * p) % MOD;
        }
        return res;
        
    }
};

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
        #endif
    return 0;
}