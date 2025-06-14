#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;
#define Test

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());      
        int i = 0, j = 1, sz = nums.size(), k = sz - 1;
        int lastNumi = -100001, lastNumj = lastNumi, lastNumk = 100001;
        vector<vector<int>> ans;
        for(i = 0;i < sz;i ++){
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            j = i + 1, k = sz - 1;
            for(;i < j && i < k && j < k && i >= 0 && k < sz;){
                int tmp = nums[i] + nums[j] + nums[k];
                if(tmp == 0){
                    if(!(nums[i] == lastNumi && nums[j] == lastNumj && nums[k] == lastNumk)){
                        ans.push_back({nums[i], nums[j], nums[k]});
                        lastNumi = nums[i];
                        lastNumj = nums[j];
                        lastNumk = nums[k];
                    }
                    -- k;
                } 
                else if(tmp > 0) -- k;
                else j ++;
            }
        }
        return ans;
    }
};

int main(){
    #ifdef Test
    #endif
    return 0;
}