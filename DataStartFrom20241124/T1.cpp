#include <iostream>
#include <cstdio>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> record;
        int n = nums.size();
        for(int i = 0;i < n;i ++){
            if(record.count(target - nums[i])){
                return {record[target - nums[i]], i};
            }
            record[nums[i]] = i;
        }
        return {};
    }
};