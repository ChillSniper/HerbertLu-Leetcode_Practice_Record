#include <bits/stdc++.h>

using namespace std;

#define Test

class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        // 这种题该如何思考呢
        // 思路越清晰，代码越简洁
        // ...
        int n = basket1.size();
        unordered_map<int, int> record;
        for (int i = 0;i < n;i ++) {
            record[basket1[i]] ++;
            record[basket2[i]] --;
        }
        vector<int> x, y;
        int min_val = INT_MAX;
        
        for (auto [num, cnt] : record) {
            if(cnt % 2) {
                return -1;
            }
            min_val = min(min_val, num);
            if(cnt > 0) {
                for (int i = 0;i < cnt / 2;i ++) {
                    x.emplace_back(num);
                }
            }
            else {
                for (int i = 0;i < -cnt / 2;i ++) {
                    y.emplace_back(num);
                }
            }
        }
        sort(x.begin(), x.end());
        sort(y.begin(), y.end(), [&](int x, int y) ->bool {
            return x > y;
        });
        long long ans = 0;
        int sz = x.size();
        for (int i = 0;i < sz;i ++) {
            ans += min(x[i], min(y[i], min_val));
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