#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
#define Test

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int sz = nums.size();
        int LastNum = 1e5, CurCnt = 0, slow = 0, fast = 0;
        for(;fast < sz && slow < sz;){
            if(nums[fast] != LastNum){
                LastNum = nums[fast];
                CurCnt = 1;
                nums[slow ++] = nums[fast ++];
            } else{
                CurCnt ++;
                if(CurCnt <= 2) nums[slow ++] = nums[fast ++];
                else fast ++;
            }
        }
        return slow;
    }
};

int main(){
    
    return 0;
}