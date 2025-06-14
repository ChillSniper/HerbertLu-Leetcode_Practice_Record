#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
    public:
        int maxSum(vector<int>& nums) {
            int sum = 0;
            unordered_set<int> st;
            int k = *max_element(nums.begin(), nums.end());
            st.insert(k);
            sum += k;
            int sz = nums.size();
            for(int i = 0;i < sz;i ++){
                if(!st.count(nums[i]) && sum + nums[i] > sum){
                    st.insert(nums[i]);
                    sum += nums[i];
                }
            }
            return sum;
        }
    };