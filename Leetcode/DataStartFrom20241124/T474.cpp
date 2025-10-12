#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> f(m + 1, vector<int>(n + 1, 0));
        int sz = strs.size();
        for(int i = 1;i <= sz;i ++){
            string& x = strs[i - 1];
            int cnt_0 = 0, cnt_1 = 0, sz_x = x.size();
            for(int i = 0;i < sz_x;i ++){
                if(x[i] == '0') cnt_0 ++;
                else if(x[i] == '1') cnt_1 ++;
            }
            if(cnt_0 <= m && cnt_1 <= n){
                for(int j = m;j >= cnt_0;j --){
                    for(int k = n;k >= cnt_1;k --){
                        f[j][k] = max(f[j][k], f[j - cnt_0][k - cnt_1] + 1);
                    }
                }
            }
        }
        return f[m][n];
    }
};