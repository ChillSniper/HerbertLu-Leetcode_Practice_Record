#include <bits/stdc++.h>
using namespace std;

#define Test

class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        // 一个比较好的思路是，直接利用两个模数之间的变换然后进行转移
        int n = nums.size();
        vector<vector<int>> f(k, vector<int>(k, 0));
        unordered_set<int> appear;
        int ans = 0;
        for(int x : nums){
            x %= k;
            for(int j = 0;j < k;j ++){
                f[j][x] = f[x][j] + 1;
                ans = max(ans, f[j][x]);
            }
        }
        return ans;
        // f[nums[0] % k][nums[1] % k] = 2;
        // for(int i = 2;i < n;i ++){
        //     int i_k = nums[i] % k;
        //     for(int j = 0;j < k;j ++){
        //         if(f[i_k][j] != 0){
        //             f[j][i_k] = f[i_k][j] + 1;
        //         }
        //         else{
        //             if(appear.count(j)){
        //                 f[j][i_k] = 2;
        //             }
        //         }
        //     }
        //     appear.insert(i_k);
        // }
        // int MaxAns = 2;
        // for(int i = 0;i < k;i ++){
        //     for(int j = 0;j < k;j ++){
        //         MaxAns = max(MaxAns, f[i][j]);
        //     }
        // }
        // return MaxAns;
    }
};

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    return 0;
}