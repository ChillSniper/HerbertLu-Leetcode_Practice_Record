#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

#define Test

class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        // 这种求 最大值的最小值 的题，可以考虑采用二分的思想解题
        // 同时我们注意到，直接用maxOperations去解题，难以下手，我们应当采用对每个nums[i]切割成不超过一定数值x
        // 的方式统计SumOfOperation，然后与maxOperations比较
        int sz = nums.size();
        int l = 1, r = *max_element(nums.begin(), nums.end());
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if(CalculateNum(nums, mid) <= maxOperations){
                r = mid;
            } 
            else 
                l = mid + 1;
        }
        return l;
    }
private:
    int CalculateNum(vector<int>& nums, int x){
        int sum = 0, sz = nums.size();
        for(int i = 0;i < sz;i ++)
            sum += (nums[i] - 1) / x;
        return sum;
    }
};

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    return 0;
}