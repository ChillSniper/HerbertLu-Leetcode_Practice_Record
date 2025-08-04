#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int cnt = 0;
        int n = fruits.size();
        for (int i = 0;i < n;i ++) {
            int cap = fruits[i];
            int j = 0;
            for (;j < n;j ++){
                if(baskets[j] >= cap){
                    baskets[j] = -1;
                    break;
                }
            }
            if(j == n) {
                ++ cnt;
            }
        }   
        return cnt;
    }
};