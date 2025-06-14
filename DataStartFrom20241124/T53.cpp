#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;
#define Test

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sz = nums.size(), MaxSum = nums[0], tmp = nums[0];
        for(int i = 1;i < sz;i ++){
            if(tmp + nums[i] >= nums[i]){
                tmp += nums[i];
                MaxSum = max(MaxSum, tmp);
            } else{
                tmp = nums[i];
                MaxSum = max(MaxSum, tmp);
            }
        }
        MaxSum = max(MaxSum, tmp);
        return MaxSum;
    }
};

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif

    return 0;
}