#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;
#define Test

const int MOD = 1e9 + 7;
class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, int> cnt_y;
        for (auto& item : points) {
            int x = item[0], y = item[1];
            cnt_y[y] ++;
        }
        vector<int> a;
        for (auto& item : cnt_y) {
            if(item.second == 1) {
                continue;
            }
            int i_s = item.second;
            a.push_back(i_s * (i_s - 1) / 2);
        }
        int sz_a = a.size();
        vector<int> Suf(sz_a, 0);
        Suf[sz_a - 1] = a[sz_a - 1];
        for(int i = sz_a - 2;i >= 0;i --){
            Suf[i] = (Suf[i + 1] + a[i]) % MOD;
        }
        int cnt = 0;
        for(int i = 0;i < sz_a - 1;i ++){
            cnt = (cnt + a[i] * Suf[i + 1] % MOD) % MOD;
        }
        return cnt;
    }
};

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    return 0;
}