#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define Test
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int len = nums.size();
        vector<int> PreMin(len);
        vector<int> SufMax(len);
        PreMin[0] = nums[0];
        for(int i = 1;i < len;i ++){
            PreMin[i] = min(nums[i], PreMin[i - 1]);
        }
        SufMax[len - 1] = nums[len - 1];
        for(int i = len - 2;i >= 0;i --){
            SufMax[i] = max(nums[i], SufMax[i + 1]);
        }
        int MaxAns = -1;
        for(int i = 1;i < len;i ++){
            if(SufMax[i] > PreMin[i - 1]){
                MaxAns = max(MaxAns, SufMax[i] - PreMin[i - 1]);
            }
        }
        return MaxAns;
    }
};
int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    return 0;
}