#include <bits/stdc++.h>
using namespace std;
#define Test

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
    // 我找到一开始的问题在哪了，我把最后面那个大的数交换a[i]的时候，没有把[i + 1, end]该区间进行逆序
    // 还有一个优化的小地方，就是在从后往前查找第一个上升区间的时刻，其之后的区间均为下降区间
        int sz = nums.size(), pos = 0;
        for(int i = sz - 2;i >= 0;i --){
            if(nums[i] < nums[i + 1]){
                for(int j = sz - 1;j > i;j --){
                    if(nums[j] >= nums[i]){
                        swap(nums[i], nums[j]);
                        pos = i + 1;
                        goto A;
                    }
                }
            }
        }
        A:
        reverse(nums.begin() + pos, nums.end());
    }
};