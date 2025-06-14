#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;
#define Test

class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        // 估计是先sort一下
        sort(nums.begin(), nums.end());
        // 这边选取数值的时候有点小问题
        // 选取p个数对，也就是要选取 p * 2 个item
        // 这个贪心算法，该怎么写呢？
        // 其实直接把每个相邻的计算过去就完事了，但是问题在于，可能会坐标重复取到
        // 我服了，这个二分居然是从差值的范围角度出发的
        int l = 0, r = 0;
        int sz = nums.size();
        for(int i = 1;i < sz;i ++){
            r = max(r, abs(nums[i] - nums[i - 1]));
        }
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            bool flag = Enable(nums, p, mid);
            if(flag){
                r = mid;
            }
            else{
                l = mid + 1;
            }
        }
        return r;
    }
private:
    bool Enable(vector<int>& nums, int p, int max_val){
        // if (b - a > max_val, we thought next.)
        int cnt = 0;
        int sz = nums.size();
        for(int i = 0;i < sz - 1;){
            int nxt_val = nums[i + 1];
            int cur_val = nums[i];
            if(abs(cur_val - nxt_val) <= max_val){
                ++ cnt;
                i += 2;
            }
            else{
                i += 1;
            }
        }
        return cnt >= p;
    }
};

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif

    return 0;
}