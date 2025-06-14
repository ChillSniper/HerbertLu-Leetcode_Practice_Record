#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define Test
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int r = nums.size() - 1, l = 0;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if(nums[mid] == target) return mid;
            if(nums[mid] > target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return -1;
    }
};
int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    return 0;
}