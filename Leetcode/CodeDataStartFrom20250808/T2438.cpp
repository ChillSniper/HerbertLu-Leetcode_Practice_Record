#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

#define Test

const int MOD = 1e9 + 7;
typedef long long ll;
class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans;
        vector<int> powers;
        int cnt = 0;
        while (n)
        {
            if(n % 2) {
                powers.emplace_back(cnt);
            }
            ++ cnt;
            n /= 2;
        }
        int sz = powers.size();
        vector<int> Pre(sz, 0);
        Pre[0] = powers[0];
        for(int i = 1;i < sz;i ++) {
            Pre[i] = Pre[i - 1] + powers[i];
        }
        int q_sz = queries.size();
        for (auto& item : queries) {
            int l = item[0], r = item[1];
            int target = 0;
            if(l > 0) {
                target = Pre[r] - Pre[l - 1];
            }
            else {
                target = Pre[r];
            }
            int val = MySelfPow(target);
            ans.emplace_back(val);
        }
        return ans;
    }
private:
    ll MySelfPow(int x) {
        if(x == 0) 
            return 1;
        ll s = 1;
        if(x % 2) {
            s = (s * 2) % MOD;
        }
        ll t = MySelfPow(x / 2) % MOD;
        return ((t * t) % MOD) * s % MOD;
    }
};

int main() {
    return 0;
}