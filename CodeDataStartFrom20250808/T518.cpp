#include <bits/stdc++.h>
using namespace std;

#define Test

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if(amount == 0) {
            return 0;
        }    
        vector<int> f(amount + 1, INT_MAX / 2);
        f[0] = 0;
        for (auto c : coins) {
            for (int v = c;v <= amount;++ v) {
                f[v] = f[v - c] >= INT_MAX / 2 ? f[v] : f[v - c] + 1; 
            }
        }
        return f[amount] >= INT_MAX / 2 ? 0 : f[amount];
    }
};

int main() {
    return 0;
}