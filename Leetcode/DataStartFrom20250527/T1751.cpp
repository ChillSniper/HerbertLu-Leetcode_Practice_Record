#include <iostream>
#include <cstdio>
#include <cstring>
#include <numeric>
#include <algorithm>
#include <vector>
using namespace std;
#define Test

class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        vector<vector<int>> f(n, vector<int>(1 + k, 0));
        sort(events.begin(), events.end(), [](auto& x, auto& y){
            return x[1] < y[1];
        });
        for(int i = 0;i < n;i ++){
            int cmp_time = events[i][0];
            // int index = lower_bound(events.begin(), events.begin() + i, cmp_time, [](auto& x, int time){
            //     return x[1] < time;
            // }) - events.begin();
            int index = partition_point(events.begin(), events.begin() + i, [](auto& e) {
                return e[1] < cmp_time;
            }) - events.begin();
            if(i == 0){
                for(int j = 1;j <= k;j ++){
                    f[i][j] = events[i][2];
                }
                continue;
            }
            for(int j = 1;j <= k;j ++){
                int value_target = index - 1 >= 0 ? f[index - 1][j - 1] : 0;
                f[i][j] = max(f[i - 1][j], value_target + events[i][2]);
            }
        }
        return f[n - 1][k];
    }
};

int main(){
    return 0;
}