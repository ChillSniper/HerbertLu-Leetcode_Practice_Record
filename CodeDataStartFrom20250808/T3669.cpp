#include <bits/stdc++.h> 
using namespace std;
#define Test


class Solution {
    public:
    vector<int> minDifference(int n, int k) {
        // 也许应当换一个更加简洁的思路，原先将所有因数拆分出来，然后处理因数数组的做法过于复杂
        // 在部分情况下，因数数组record长度n较大，n!无法保证不会TLE
        // 实际上，这也是一种逆向思维，从n向因数进行递归。与此同时，预处理的步骤值得注意，还有这个很妙的预处理方式

        global_k = k;
        MinDis = 0x3f3f3f3f;
        for (int i = 1;i <= n;i ++) {
            for (int j = i;j <= n;j += i) {
                Factor[j].emplace_back(i);
            }
        }
       
        int min_val = 0x3f3f3f3f, max_val = 0;
        vector<int> path(k);
        Dfs(path, 0, min_val, max_val, n, 0);
        return ans;
    }
    private:
    int MinDis, global_k;
    vector<int> ans;
    static const int N = 1e5 + 10;
    vector<int> Factor[N];
    void Dfs(vector<int>& path, int index, int min_val, int max_val, int cur, int last_val) {
        // 我他妈的知道问题出哪了 出在这个min_val和max_val上
        
        if(index == global_k - 1) {
            path[index] = cur;
            min_val = min(min_val, cur);
            max_val = max(max_val, cur);
            if(max_val - min_val < MinDis) {
                MinDis = max_val - min_val;
                ans = path;
            }
            return ;
        }
        for (auto item : Factor[cur]) {
            if(item >= last_val) {
                int fk_min_val = min(min_val, item);
                int fk_max_val = max(max_val, item);
                path[index] = item;
                Dfs(path, index + 1, fk_min_val, fk_max_val, cur / item, item);
            }
        }
    }   
};


int main() {
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    int n = 65536, k = 5;
    Solution s;
    vector<int> ans = s.minDifference(n, k);
    for (auto item : ans) {
        cout << item << " ";
    }
    return 0;
}