#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define Test

class Solution {
public:
    int rob(vector<int>& nums) {
        int sz = nums.size();
        if(sz == 1){
            return nums[0];
        }

        vector<int> f(sz, 0);
        f[0] = nums[0];
        f[1] = nums[1];
        for(int i = 2;i < sz;i ++){
            f[i] = max(f[i - 2] + nums[i], f[i - 1]);
        }
        int val = *max_element(f.begin(), f.end());
        return val;    
    }
};

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    return 0;
}