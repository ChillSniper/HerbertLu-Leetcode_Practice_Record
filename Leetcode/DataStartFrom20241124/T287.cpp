#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int sl = 0, fs = 0;
        sl = nums[sl];
        fs = nums[nums[fs]];
        while (sl != fs)
        {
            sl = nums[sl];
            fs = nums[nums[fs]];
        }
        sl = 0;
        while (sl != fs)
        {
            sl = nums[sl];
            fs = nums[fs];
        }
        return nums[sl];
    }
};