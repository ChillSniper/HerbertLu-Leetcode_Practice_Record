#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define Test

class Solution {
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> g(n);
        for (auto& item : edges) {
            int u = item[0], v = item[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }      
        vector<int> xr(n), in(n), out(n);
        int clock = 0;
        auto dfs = [&](this auto && dfs, int cur, int f) ->void {
            // pay attention that it is a tree not a grid.
            in[cur] = ++ clock;
            xr[cur] = nums[cur];
            for (auto& v : g[cur]) {
                if(v == f){
                    continue;
                }
                dfs(v, cur);
                // 服了，找了一个多小时bug，问题居然出在这里，鬼知道当时怎么把xr打成num了
                xr[cur] ^= xr[v];
            }
            out[cur] = clock;
        };

        dfs(0, -1);
        int ans = INT_MAX;

        for (int y2 = 2;y2 < n;++ y2) {
            for (int y1 = 1;y1 < y2;++ y1) {
                // int f1 = father[y1], f2 = father[y2];
                // three situations
                // 1. in[y1] < in[x2]  <= out[y1]
                
                // 2. in[y2] < in [x1] <= out[y2]
                // 3. ... others
                int a, b, c;
                if(in[y1] < in[y2] && in[y2] <= out[y1]){
                    a = xr[y2];
                    b = xr[y1] ^ xr[y2];
                    c = xr[0] ^ xr[y1];
                } 
                else if(in[y2] < in[y1] && in[y1] <= out[y2]){
                    a = xr[y1];
                    b = xr[y2] ^ xr[y1];
                    c = xr[0] ^ xr[y2];
                } 
                else {
                    a = xr[y1];
                    b = xr[y2];
                    c = xr[0] ^ xr[y1] ^ xr[y2];
                }
                int max_val = max({a, b, c});
                int min_val = min({a, b, c});
                ans = min(ans, max_val - min_val);
            }
        }
        return ans;
    }
};

int main(){

    return 0;
}