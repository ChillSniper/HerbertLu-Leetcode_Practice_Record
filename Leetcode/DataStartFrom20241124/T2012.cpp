#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define Test

const int INF = 0x3f3f3f3f;
class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int sz = nums.size();
        vector<int> f_Max(sz, -INF), f_Min(sz, INF);
        f_Max[0] = nums[0];
        for(int i = 1;i < sz;i ++){
            f_Max[i] = max(f_Max[i - 1], nums[i]);
        }
        f_Min[sz - 1] = nums[sz - 1];
        for(int i = sz - 2;i >= 0;i --)
            f_Min[i] = min(f_Min[i + 1], nums[i]);
        int sum = 0;
        for(int i = 1;i <= sz - 2;i ++){
            if(nums[i] > f_Max[i - 1] && nums[i] < f_Min[i + 1])
                sum += 2;
            else if(nums[i] > nums[i - 1] && nums[i] < nums[i + 1])
                sum += 1;

        }
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