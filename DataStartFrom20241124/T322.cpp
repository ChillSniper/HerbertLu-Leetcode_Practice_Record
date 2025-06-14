#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define Test

// #define DfsWay
#define DpWay

#ifdef DpWay
const int INF = 0x3f3f3f3f;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> f(amount + 1, INF);
        f[0] = 0;
        for(int i = 1;i <= amount;i ++){
            for(auto& coin : coins){
                if(coin <= i)
                    f[i] = min(f[i], f[i - coin] + 1);
            }
        }
        return f[amount];
    }
};
#endif

#ifdef DfsWay
const int INF = 0x3f3f3f3f;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        ans.resize(amount + 1, 0);
        return dp(coins, amount);
    }
private:
    vector<int> ans;
    int dp(vector<int>& coins, int remain){
        if(remain < 0)
            return -1;
        if(remain)
            return 0;
        if(ans[remain] != 0)
            return ans[remain];
        int MinAns = INF;
        for(auto& coin : coins){
            int t = dp(coins, remain - coin);
            if(t >= 0 && t < MinAns){
                MinAns = t + 1;
            }
        }   
        ans[remain] = MinAns != INF ? MinAns : -1;
        return ans[remain];
    }
};
#endif

int main(){
    return 0;
}