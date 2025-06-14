#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int SlowPosition  = 0;
        for(int i = 0;i < nums.size();i ++){
            if(nums[i] != 0)
                nums[SlowPosition ++] = nums[i];
        }
        for(int i = SlowPosition;i < nums.size();i ++)  
            nums[i] = 0;
    }
};

int main(){
    return 0;
}