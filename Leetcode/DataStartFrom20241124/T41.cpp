#include <iostream>
#include <cstdio>
#include <cstring>
#include <unordered_set>
#include <algorithm>
#include <vector>
using namespace std;
#define Test

// #define MyWay
#define BetterWay

#ifdef BetterWay
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int sz = nums.size();
        for(int i = 0;i < sz;i ++){
            while (1)
            {
                int x = nums[i];
                if(x <= 0 || x > sz) break;
                int pos = x - 1;
                if(pos == i) break;
                swap(nums[pos], nums[i]);
            }
        }
        for(int i = 0;i < sz;i ++){
            if(nums[i] != i + 1) return i + 1;
        }
        return sz + 1;
    }
};
#endif

#ifdef MyWay
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int sz = nums.size(), Min = 1;
        unordered_set<int> st;
        for(int i = 0;i < sz;i ++){
            st.insert(nums[i]);
        }
        while (st.count(Min))
        {
            Min ++;
        }
        return Min;
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