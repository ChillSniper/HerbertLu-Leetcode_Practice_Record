#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define Test


const int N = 5e4 + 10, M = 1e5 + 10;
int Head[N], idx, Nxt[M], To[M], weight[M];

class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        // 很考查思维的一道题，最大化最小值，要联想到二分算法！
        idx = 0;
        memset(Head, -1, sizeof Head);
        memset(Nxt, 0, sizeof Nxt);
        memset(To, 0, sizeof To);
        int n = online.size(), RightVal = 0;
        for (auto& item : edges) {
            int u = item[0], v = item[1], w = item[2];
            if(online[u] && online[v]){
                AddEdge(u, v, w);
                RightVal = max(RightVal, w);
            }
        }
        vector<long long> record(n);
        auto check = [&](int lower) ->bool {
            ranges::fill(record, -1);
            auto dfs = [&](this auto&& dfs, int u) ->long long {
                if(u == n - 1){
                    return 0;
                }
                auto& cur = record[u];
                if(cur != -1){
                    return cur;
                }
                cur = LLONG_MAX / 2;
                for (int i = Head[u];i != -1;i = Nxt[i]) {
                    int v = To[i], w = weight[i];
                    if(w >= lower){
                        cur = min(cur, dfs(v) + w);
                        // 由于这边递归的时候可能会返回到先前赋值cur给LLONG_MAX的情形，所以要将LLONG_MAX / 2防止溢出
                    }
                }

                return cur;
            };
            return dfs(0) <= k;
        };
        int LeftVal = 0;
        while (LeftVal <= RightVal)
        {
            int mid = (LeftVal + RightVal) / 2;
            bool Flag = check(mid);
            if(Flag){
                LeftVal = mid + 1;
            } else{
                RightVal = mid - 1;
            }
        }   
        return RightVal ? RightVal : -1;
    }
private:
    void AddEdge(int u, int v, int w){
        Nxt[idx] = Head[u];
        To[idx] = v;
        weight[idx] = w;
        Head[u] = idx ++;
    }
};

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    return 0;
}