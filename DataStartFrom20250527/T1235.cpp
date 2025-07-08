#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <array>
#include <vector>
#include <numeric>

using namespace std;
#define Test

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> rec(n);
        for(int i = 0;i < n;i ++){
            rec[i] = {startTime[i], endTime[i], profit[i]};
        }
        sort(rec.begin(), rec.end(), [](auto& x, auto& y){
            return x[1] < y[1];
        });
        vector<int> f(n, 0);
        for(int i = 0;i < n;i ++){
            int cmp_time = rec[i][0];
            int index = upper_bound(rec.begin(), rec.begin() + i, cmp_time, [](int time, auto& r){
                return time < r[1];
            }) - rec.begin();
            
            if(i == 0){
                f[0] = rec[i][2];
                continue;
            }
            int target = index - 1 >= 0 ? f[index - 1] : 0;
            f[i] = max(f[i - 1], target + rec[i][2]);
        }
        return f[n - 1];
    }
};

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    return 0;
}