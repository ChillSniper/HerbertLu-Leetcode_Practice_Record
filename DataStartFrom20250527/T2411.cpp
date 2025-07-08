#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define Test

// #define Way1
#define Way2

#ifdef Way2
// 这个模板细节很多，很容易写错。。。
class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        // 这个的话，后加入的元素对截止的右端早。
        // 而且，如果以左端相同，或和值等的元素组右端是连续的
        int n = nums.size();
        vector<int> ans(n);
        vector<pair<int, int>> rec;
        for(int i = n - 1;i >= 0;i --){
            rec.emplace_back(0, i);
            int cur_val = nums[i];
            rec[0].first |= cur_val;
            int k = 0;
            for(int j = 1;j < rec.size();j ++){
                rec[j].first |= cur_val;
                if(rec[k].first == rec[j].first){
                    rec[k].second = rec[j].second;
                }
                else{
                    rec[++ k] = rec[j];
                }
            }
            rec.resize(k + 1);
            ans[i] = rec[0].second - i + 1;
        }
        return ans;
    }
};
#endif

#ifdef Way1
// 朴素做法
class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        // 朴素做法，其实这个也不太好想
        // 这太坑了，注意这个"|"，这个符号的运算优先级要比 ">" 低！
        int sz = nums.size();
        vector<int> ans(sz, 1);
        for(int i = 1;i < sz;i ++){
            int x = nums[i], j = i - 1;
            while (j >= 0 && ((nums[j] | x) > nums[j]))
            {
                nums[j] = x | nums[j];
                ans[j] = i - j + 1;
                -- j;
            }
        }
        return ans;
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