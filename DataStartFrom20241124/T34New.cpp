#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define Test

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int sz = nums.size(), l = 0, r = sz - 1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if(nums[mid] >= target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        l = (l >= 0 && l < sz) ? l : -1;
        ans.push_back(l);
        l = 0, r = sz - 1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if(nums[mid] > target)
                r = mid - 1;
            else 
                l = mid + 1;
        }
        r = (r >= 0 && r < sz) ? r : -1;
        ans.push_back(r);
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