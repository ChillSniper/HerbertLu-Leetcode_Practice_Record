#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int MaxSum = 0, RecordInterval = 0;
        MaxSum = RecordInterval = nums[0];
        for(int i = 1;i < nums.size();i ++){
            if(RecordInterval > 0) RecordInterval += nums[i];
            else RecordInterval = nums[i];
            MaxSum = max(RecordInterval, MaxSum);
        }
        return MaxSum;
    }

};

int main(){

    return 0;
}