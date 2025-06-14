#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
#define Test

// #define MyWay
#define BetterWay

#ifdef BetterWay
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};
#endif

#ifdef MyWay
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int sz = nums.size();
        k = k % sz;
        stack<int> st;
        for(int i = sz - 1;i >= sz - 1 - k + 1;i --) st.push(nums[i]);
        for(int i = sz - 1;i >= k;i --) nums[i] = nums[i - k];
        for(int i = 0;i < k;i ++){
            nums[i] = st.top(); st.pop();
        }
    }
};
#endif

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif

    return 0;
}