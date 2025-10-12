#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
#define Test

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // 此题不可以使用滑动窗口做，因为和可能是负值，没法朝一个方向移动
        // 应当使用前缀和
        int cnt = 0, sz = nums.size(), CurSum = 0;
        unordered_map<int, int > ump;
        // ump.emplace(pair(0, 0));
        ump[0] = 1;
        for(int i = 0;i < sz;i ++){
            CurSum += nums[i];
            int x = CurSum - k ;
            if(ump.count(x)) cnt += ump[x];
            ump[CurSum] ++;
        }
        return cnt;
    }
};

int main(){

    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    vector<int> num = {1, 1, 1};
    int k = 2;
    Solution example;
    cout << example.subarraySum(num, k);
    return 0;
}