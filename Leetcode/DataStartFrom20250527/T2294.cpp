#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        // 每个子序列中元素越多越好。      
        int cnt = 0;
        sort(nums.begin(), nums.end());
        int cur_num = nums[0], sz = nums.size();
        for(int i = 1;i < sz;i ++){
            if(nums[i] - cur_num <= k){
                ;
            }
            else{
                cnt ++;
                cur_num = nums[i];
            }
        }   
        ++ cnt;
        return cnt;
    }
};

#define Test
int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    return 0;
}