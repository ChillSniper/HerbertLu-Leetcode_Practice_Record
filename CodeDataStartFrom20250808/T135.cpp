#include <bits/stdc++.h>
using namespace std;

#define Test

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> l(n, 1), r(n, 1);
        for (int i = 1;i < n;i ++) {
            if(ratings[i] > ratings[i - 1]) {
                ++ l[i];
            }
        }
        for (int i = n - 2;i >= 0;i --) {
            if(ratings[i] > ratings[i + 1]) {
                ++ r[i];
            }
        }
        int ans = 0;
        for (int i = 0;i < n;i ++) {
            ans += max(l[i], r[i]);
        }
        return ans;
    }
};

int main() {
    return 0;
}