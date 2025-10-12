#include <bits/stdc++.h>
using namespace std;

#define Test

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int cur = 0, Minval = 0, ans = -1;
        int gas_sum = 0, cost_sum = 0;
        for (auto item : gas) 
            gas_sum += item;
        for (auto item : cost) 
            cost_sum += item;
        if(gas_sum < cost_sum)
            return -1;
        for (int i = 0;i < n;i ++) {
            cur += gas[i] - cost[i];
            if(cur < Minval) {
                Minval = cur;
                ans = (i + 1) % n;
            }
        } 
        return ans;
    }
};

int main() {

    return 0;
}