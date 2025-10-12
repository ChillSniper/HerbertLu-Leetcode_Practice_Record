#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define Test

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int sz = nums.size();
        vector<vector<int>> tmp(sz);
        sort(nums.begin(), nums.end());
        for(int i = 0;i < sz;i ++){
            int j = i, curNum = nums[i], idx = 0;
            while (j < sz && nums[j] == curNum)
            {
                tmp[idx].push_back(nums[j]);
                idx ++;
                j ++;
            }
            i = j - 1;
        }
        vector<vector<int>> ans;
        for(int i = 0;i < sz;i ++){
            int cur_sz = tmp[i].size();
            if(cur_sz == 0)
                break;
            ans.push_back(tmp[i]);
        }
        return ans;
    }
};

int main(){

    return 0;
}