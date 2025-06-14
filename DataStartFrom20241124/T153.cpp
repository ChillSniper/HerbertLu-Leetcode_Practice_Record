#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define Test

const int INF = 0x3f3f3f3f;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans = INF, sz = nums.size(), l = 0, r = sz - 1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if(nums[l] <= nums[mid]){
                ans = min(ans, nums[l]);
                l = mid + 1;
            }
            else{
                ans = min(ans, nums[mid + 1]);
                r = mid;
            }
        }
        return ans;
    }
};

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    return 0;
}