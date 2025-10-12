#include <iostream>
#include <cstdio>
#include <cstring>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define Test

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int sz = nums.size();
        vector<int> ans;
        deque<pair<int, int>> dq;
        for(int i = 0;i < k;i ++){
            if(dq.empty()) dq.push_back(pair(i, nums[i]));
            else{
                if(nums[i] <= dq.back().second){
                    dq.push_back(pair(i, nums[i]));
                } else{
                    while (!dq.empty() && dq.back().second < nums[i])
                    {
                        dq.pop_back();
                    }
                    dq.push_back(pair(i, nums[i]));
                }
            }
        }
        ans.push_back(dq.front().second);
        for(int i = k;i < sz;i ++){
            if(dq.front().first <= i - k)
                dq.pop_front();
            if(dq.empty()) dq.push_back(pair(i, nums[i]));
            else{
                if(nums[i] <= dq.back().second){
                    dq.push_back(pair(i, nums[i]));
                } else{
                    while (!dq.empty() && dq.back().second < nums[i])
                    {
                        dq.pop_back();
                    }
                    dq.push_back(pair(i, nums[i]));
                }
            }
            ans.push_back(dq.front().second);
        }
        return ans;
    }
};

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    vector<int> num = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    Solution ex;
    ex.maxSlidingWindow(num, k);
    return 0;
}