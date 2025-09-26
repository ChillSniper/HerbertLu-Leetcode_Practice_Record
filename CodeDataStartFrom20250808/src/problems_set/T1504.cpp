#include <bits/stdc++.h>
using namespace std;

#define Test

class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        // 又是这种...
        // 该从何下手呢
        int m = mat.size(), n = mat[0].size();
        int ans = 0;
        for (int i = 0;i < m;i ++) {
            vector<int> record(n + 1, 0);
            for (int j = i;j < m;j ++) {
                for (int k = 0;k < n;k ++) {
                    record[k] += mat[j][k];
                }
                int h = j - i + 1, cur_len = 0;
                for (int k = 0;k <= n;k ++) {
                    if(record[k] == h) {
                        ++ cur_len;
                    }
                    else {
                        ans += (1 + cur_len) * cur_len / 2;
                        cur_len = 0;
                    }
                }
            }
        }
        return ans;
    }
};

int main() {
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    return 0;
}