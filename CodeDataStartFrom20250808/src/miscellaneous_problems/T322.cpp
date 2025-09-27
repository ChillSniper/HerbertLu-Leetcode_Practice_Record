#include <bits/stdc++.h>
using namespace std;

#define Test

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) {
            return 0;
        }      
        vector<int> f(amount + 1, INT_MAX / 2); 
        f[0] = 0;
        for (auto c : coins) {
            for (int v = c;v <= amount;v ++) {
                f[v] = min(f[v - c] + 1, f[v]);
            }
        }
        return f[amount] >= INT_MAX / 2 ? -1 : f[amount];
    }

};

int main() {

    return 0;
}