#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_map>
using namespace std;
#define Test

typedef long long ll;
class Solution {
public:
    long long minimumCost(string s) {
        int sz = s.size();
        ll ans = 0;
        for(int i = 1;i < sz;i ++){
            if(s[i] != s[i - 1]){
                // min(i, sz - i)
                ans += min(i, sz - i);
            }
        }   
        return ans;
    }
};