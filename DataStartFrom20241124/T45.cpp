#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    public:
        int jump(vector<int>& nums) {
            int st = 0, end = 1, ans = 0, MaxPos = 0, sz = nums.size();
            while (end < nums.size())
            {
                for(int i = st;i < end;i ++){
                    MaxPos = max(MaxPos, i + nums[i]);
                }
                st = end;
                end = min(MaxPos, sz);
                ans ++;
            }
            return ans;
        }
    };