#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0, k = n - 1;
        while (j <= k) // 注意此处的特判条件
        {
            if(nums[j] == 0){
                swap(nums[j], nums[i]);
                i ++; j ++; // 其实此处对于为什么j ++就很奇怪
                // 注意到i, j在这种划分算法下是同步进行的过程
            } else if(nums[j] == 2){
                swap(nums[j], nums[k]);
                k --;
            } else{
                j ++;
            }
        }
    }
};