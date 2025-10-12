#include <iostream>
#include <cstdio>
#include <unordered_map>
#include <stack>
#include <vector>
using namespace std;
//#define MyWay
#define CycleWay

#ifdef CycleWay
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> ans(n, -1);
        for(int i = 0;i < 2 * n;i ++){
            // 1 2 1
            while (!st.empty() && nums[st.top()] < nums[i % n])
            {
                ans[st.top()] = nums[i % n];
                st.pop();
            }
            st.push(i % n);
        }
        return ans;
    }
};
#endif

#ifdef MyWay
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0;i < n;i ++) nums.push_back(nums[i]);
        stack<int> st;
        vector<int> ans(n);
        for(int i = 2 * n - 1;i >= 0;i --){
            while (!st.empty() && st.top() <= nums[i])
            {
                st.pop();
            }
            int j = i;
            if(j >= n) j -= n;
            if(st.empty()) ans[j] = -1;
            else ans[j] = st.top();
            st.push(nums[i]);
        }
        return ans;
    }
};
#endif

int main(){
    freopen("file.in", "r", stdin);
    freopen("file.out", "w", stdout);
    Solution s;
    vector<int> test = {1, 2, 1};
    vector<int> ans = s.nextGreaterElements(test);
    return 0;
}