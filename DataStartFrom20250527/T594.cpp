#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
#define Test

class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int, int> cnt;
        for(auto item : nums){
            cnt[item] ++;
        }
        int lastNum = -1, lastCnt = 0, MaxLength = 0;
        for(auto item : cnt){
            int cur_key = item.first, cnt_val = item.second;
            if(cur_key == lastNum + 1){
                MaxLength = max(MaxLength, cnt_val + lastCnt);
            }
            lastNum = cur_key;
            lastCnt = cnt_val;
        }
        return MaxLength;
    }
};

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    return 0;
}