#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

#define Test

typedef long long ll;
class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        ll ans = 0;
        unordered_map<int, int> cnt;
        for (auto item : basket1) {
            cnt[item] ++;
        }    
        for (auto item : basket2) {
            cnt[item] ++;
        }
        for (auto item : cnt) {
            if(item.second % 2){
                return -1;
            }
        }
        
    }
};

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    return 0;
}