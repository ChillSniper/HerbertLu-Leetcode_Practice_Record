#include <bits/stdc++.h>
using namespace std;
#define Test

class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int fs, sl, n = nums.size(), cnt = 0;
        for (fs = 1, sl = 1;fs < n;){
            if(nums[fs] == nums[fs - 1]){
                ++ fs;
            }
            else{
                nums[sl ++] = nums[fs ++];
            }
        }
        nums.resize(sl);
        n = sl;
        for(int i = 1;i < n - 1;i ++){
            if((nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) ||(nums[i] < nums[i - 1] && nums[i] < nums[i + 1])){
                ++ cnt;
            }
        }
        return cnt;
    }
};

int main(){
    #ifdef Test
    #endif
    return 0;
}