#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {  
        int sz_q = queries.size(), sz_num = nums.size(), zero_flag = true;
        for(int i = 0;i < sz_num;i ++){
            if(nums[i]){
                zero_flag = false;
                break;
            }
        }
        if(zero_flag)
            return 0;
        vector<vector<int>> f(sz_num);
        for(int i = 0;i < sz_num;i ++){
            f[i].resize(nums[i] + 1);
            f[i][0] = 1;
        }
        for(int i = 0;i < sz_q;i ++){
            auto& q = queries[i];
            int val = q[2];
            for(int l = q[0];l <= q[1];l ++){
                if(f[l][nums[l]])
                    continue;
                for(int j = nums[l];j >= val;j --)
                    f[l][j] = f[l][j] || f[l][j - val];
            }
            bool flag = true;
            for(auto f_i : f){
                if(f_i.back() == 0){
                    flag = false;
                    break;
                }
            }
            if(flag)
                return i + 1;
        }
        return -1;
    }
};

int main(){

    return 0;
}