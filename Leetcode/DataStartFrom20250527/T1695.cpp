#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define Test

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int i = 0, j = 0, ans = 0, sum = 0;
        unordered_set<int> record;
        int n = nums.size();
        for(;i <= j && j < n;){
            if(!record.count(nums[j])){
                record.insert(nums[j]);
                sum += nums[j];
                ans = max(ans, sum);
                ++ j;
            }
            else{
                while (i < j)
                {
                    sum -= nums[i];
                    record.erase(nums[i]);
                    if(nums[i] == nums[j]){
                        ++ i;
                        break;
                    }
                    ++ i;
                }
            }
        }
        return ans;
    }
};

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif

    return 0;
}