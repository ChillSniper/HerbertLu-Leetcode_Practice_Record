#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
    public:
        int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
            int sz_q = queries.size();
            for(int i = 0;i < sz_q;i ++){
                int l = queries[i][0], r = queries[i][1], val = queries[i][2];
                for(int j = l;j <= r;j ++)
                    nums[j] -= val;
                
                if(Check(nums))
                    return i + 1;
            }
            return -1;
        }
    private:
        bool Check(vector<int>& num){
            int sz = num.size();
            for(int i = 0;i < sz;i ++){
                if(num[i] != 0)
                    return false;
            }
            return true;
        }
};