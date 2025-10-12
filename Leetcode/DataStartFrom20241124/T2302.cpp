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
    long long countSubarrays(vector<int>& nums, long long k) {
        // 首先不难想到使用前缀和
        int sz = nums.size();
        vector<ll> Sum(sz + 1, 0);
        for(int i = 1;i <= sz;i ++){
            Sum[i] = Sum[i - 1] + nums[i - 1];
        }
        int i = 1, j = 1;
        ll cnt = 0;
        while (i <= j && j <= sz)
        {
            if((Sum[j] - Sum[i - 1]) * (j - i + 1) < k){
                cnt += (j - (i - 1));
                j ++;
            }
            else{
                i ++;
                if(i > j){
                    j ++;
                }
            }
        }
        return cnt;
    }
};

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif

    return 0;
}