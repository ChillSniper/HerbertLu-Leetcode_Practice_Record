#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int sz = nums.size();
        int target = 0;
        for(int i = 0;i < sz;i ++)
            target = nums[i] xor target;
        return target;
    }
};