#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> largestDivisibleSubset(vector<int>& nums) {
            // 这个数据量打暴搜不是扯淡么
            // 可以考虑O(n^2)的做法
            int sz = nums.size();
            sort(nums.begin(), nums.end());
            vector<int> f(sz, 0), Pos(sz, -1);
            for(int i = 0;i < sz;i ++){
                int Ans = 0, pos_target = -1;
                for(int j = 0;j < i;j ++){
                    if(nums[i] % nums[j] == 0 && f[j] > Ans){
                        Ans = f[j];
                        pos_target = j;
                    }
                }
                f[i] = Ans + 1;
                Pos[i] = pos_target;
            }
            int max_pos = max_element(f.begin(), f.end()) - f.begin();
            vector<int> ans;
            while (max_pos != -1)
            { 
                ans.emplace_back(nums[max_pos]);
                max_pos = Pos[max_pos];
            }
            return ans;
        }
    };