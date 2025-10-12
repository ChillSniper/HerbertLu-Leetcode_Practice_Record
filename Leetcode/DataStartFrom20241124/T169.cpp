#include <bits/stdc++.h>
using namespace std;
#define Test
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> ump;
        int sz = nums.size();
        int target = sz / 2 + 1;
        for(auto item : nums){
            ump[item] ++;
            if(ump[item] >= target)
                return item;
        }
        return -1;
    }
};