#include <bits/stdc++.h>
using namespace std;

#define Test

typedef long long ll;
class Solution {
public:
    long long minArraySum(vector<int>& nums, int k) {
        int n = nums.size();
        ll ans = 0;
        vector<int> new_num(n + 1, 0);
        for (int i = 0;i < n;i ++) {
            new_num[i + 1] = nums[i];
        }
        vector<int> Pre(n + 1, 0);
        for (int i = 1;i <= n;i ++) {
            Pre[i] = Pre[i - 1] + new_num[i];
        }
        int add_l = 0, add_r = 1, cur = 0;
        unordered_map<int, int> record;
        record[0] = 0;
        for (;add_r <= n;) {
            cur += new_num[add_r];
            int p = cur % k;
            if(record.count(p)) {
                int re_l = record[p];
                ans += Pre[re_l] - Pre[add_l];
                cur = 0;
                add_l = add_r;
                record.clear();
                record[0] = add_l;
            }
            else {
                record[p] = add_r;
            }
            ++ add_r;
        }
        int p = cur % k;
        if(record.count(p) && record[p] == n) {
            int re_l = record[p];
            ans += Pre[re_l] - Pre[add_l];
        }
        return ans;
    }
};

int main() {
    vector<int> num = {71,91,43,49,80,93,65};
    int k = 205;
    Solution s;
    cout << s.minArraySum(num, k);
    return 0;
}