#include <bits/stdc++.h>
using namespace std;
#define Test

typedef long long ll;
class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int q_sz = questions.size();
        vector<ll> f(q_sz, 0);
        
        for(int i = 0;i < q_sz;i ++){
            ll score = questions[i][0];
            int step = questions[i][1], des = i + step + 1;
            if(i + 1 < q_sz){
                f[i + 1] = max(f[i], f[i + 1]);
            }
            f[i] += score;
            if(des < q_sz){
                f[des] = max(f[des], f[i]);
            }
        }    
        return *max_element(f.begin(), f.end());
    }
};