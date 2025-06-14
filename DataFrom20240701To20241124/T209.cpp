#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int CurrentSum = 0;
        int LeftPointer = 0;
        int RightPointer = 0;
        int MinLength = nums.size();
        for(RightPointer = 0;RightPointer < nums.size();RightPointer ++){
            CurrentSum += nums[RightPointer];
            if(CurrentSum >= target){
                while (CurrentSum - nums[LeftPointer] >= target && LeftPointer < RightPointer)
                {
                    CurrentSum -= nums[LeftPointer];
                    LeftPointer ++;
                }
                MinLength = min(MinLength, RightPointer - LeftPointer + 1);
            }
        }
        if(CurrentSum >= target)
            return MinLength;
        else return 0;
    }
};

int main(){

    return 0;
}