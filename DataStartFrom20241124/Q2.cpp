#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <cmath>
using namespace std;

const int INF = 0x3f3f3f3f;
class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        // 暂时没什么一个确定的思路
        // 先从前往后遍历 当map中之前储存过元素的话，把位置调出来，然后作为距离差值
        // 然后map存进去新的
        int sz = nums.size();
        vector<int> ans(sz, INF);
        unordered_map<int, int> ump;
        for(int i = 0;i < 2 * sz;i ++){
            int index = i % sz;
            if(ump.count(nums[index])){
                int lastIndex = ump[nums[index]];
                ans[lastIndex] = min(INF, min(abs(index - lastIndex), abs(lastIndex + sz - index) % sz));
                ans[index] = ans[lastIndex];
                ump[nums[index]] = index;
            }
            else{
                ump[nums[index]] = index;
            }
        }
        vector<int> res;
        int sz_que = queries.size();
        for(int i = 0;i < sz_que;i ++){
            res.push_back(ans[queries[i]]);
        }
        return res;
    }
};