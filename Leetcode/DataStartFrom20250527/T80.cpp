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
        int sl = 1, fs = 1, sz = nums.size(), cur_cnt = 1, cur_val = nums[0];
        if(sz == 1){
            return 1;
        }
        for(;sl < sz && fs < sz;){
            if(nums[fs] == cur_val){
                cur_cnt ++;
                if(cur_cnt <= 2){
                    nums[sl ++] = nums[fs ++];
                }
                else{
                    fs ++;
                }
            }
            else{
                cur_cnt = 1;
                cur_val = nums[fs];
                nums[sl ++] = nums[fs ++];
            }
        }
        nums.resize(sl);
        return sl;
    }
};

int main(){
    return 0;
}