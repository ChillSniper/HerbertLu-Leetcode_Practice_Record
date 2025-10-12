#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
#define Test

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int sz = nums.size();
        vector<int> flag(sz, 0);
        flag[0] = 1;
        int MaxReach = 0;
        for(int i = 0;i < sz;i ++){

            if(MaxReach >= i)
                flag[i] = 1;

            if(flag[i])
                MaxReach = max(MaxReach, i + nums[i]);
        
        }
        return flag[sz - 1];
    }
};

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    return 0;
}