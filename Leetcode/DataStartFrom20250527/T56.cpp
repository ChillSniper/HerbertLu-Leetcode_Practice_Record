#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define Test

bool cmp(vector<int> a, vector<int> b){
    if(a[0] == b[0])
        return a[1] < b[1];
    return a[0] < b[0];
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end(), cmp);
        int len = intervals.size(), l = -1, r = -1;
        for(int i = 0;i < len;i ++){
            int cur_l = intervals[i][0], cur_r = intervals[i][1];
            if(cur_l > r){
                if(!(l == -1 && r == -1)){
                    ans.push_back({l, r});
                }
                l = cur_l;
                r = cur_r;
            }
            else if(cur_l <= r){
                // r = cur_r;
                r = max(r, cur_r);
            }
        }
        ans.push_back({l, r});
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