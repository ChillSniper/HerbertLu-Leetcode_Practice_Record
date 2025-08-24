#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pr;
class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0), pos(n, 0);
        int MaxNum = 0, cur_pos = 0;
        for (int i = 0;i < n;i ++) {
            if(MaxNum > nums[i]) {
                ans[i] = MaxNum;
                pos[i] = cur_pos;
            }
            else {
                ans[i] = nums[i];
                MaxNum = nums[i];
                cur_pos = i;
            }
        }
        // 这道题的问题在于要往后跳
        // 也就是说，位置i处能跳到的最大值，是前向的最大值a和后续能跳到的最高值b，然后取max(a, b)
        // 问题在于b怎么求
        map<int, int> record;
        for (int i = n - 1;i >= 0;i --) {
            int cur_val = nums[i];
            auto it = record.lower_bound(cur_val);
            if(it == record.begin()) {
                // record[cur_val] = ans[i];
            }
            else {
                -- it;
                ans[i] = max(ans[i], it->second);
                // record[cur_val] = ans[i];
            }
            int fk_val = nums[pos[i]];
            it = record.lower_bound(fk_val);
            if(it == record.begin()) {
                ;
            }
            else {
                -- it;
                ans[i] = max(ans[i], it->second);
                // record[cur_val] = ans[i];
            }
            record[cur_val] = ans[i];
        }
        
        return  ans;
    }
};