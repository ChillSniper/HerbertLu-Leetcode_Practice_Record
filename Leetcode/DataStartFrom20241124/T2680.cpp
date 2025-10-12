#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define Test

typedef long long ll;
class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        int sz = nums.size();
        vector<int> Pre(sz, 0), Suf(sz, 0);
        int ls = 0, bf = 0;
        ll ans = 0;
        for(int i = 0;i < sz;i ++){
            Pre[i] = bf | nums[i];
            bf = Pre[i];
        }
        for(int i = sz - 1;i >= 0;i --){
            Suf[i] = ls | nums[i];
            ls = Suf[i];
        }
        for(int i = 0;i < sz;i ++){
            ll x = nums[i] << k;
            if(i > 0)
                x |= Pre[i - 1];
            if(i + 1 < sz)
                x |= Suf[i + 1];
            
            ans = max(ans, x);
        }
        return ans;
    }
};

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    return 0;
}