#include <bits/stdc++.h>
using namespace std;

#define Test

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int max_val = -1;
        int ans = 0, sz = nums.size(), cur_len = 0;
        for (int i = 0;i < sz;i ++) {
            if(nums[i] == max_val) {
                ++ cur_len;
                ans = max(ans, cur_len);
            } 
            else if(nums[i] > max_val){
                max_val = nums[i];
                cur_len = 1;
                ans = cur_len;
            }
            else{
                cur_len = 0;
            }
        }
        return ans;
    }
};

int main(){

    return 0;
}