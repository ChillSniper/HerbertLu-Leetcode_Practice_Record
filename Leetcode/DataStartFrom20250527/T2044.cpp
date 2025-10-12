#include <bits/stdc++.h>
using namespace std;

#define Test
class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        // 服了，以后看题要过一下数据范围，这个题我一开始还想是不是dp，结果是暴力回溯
        ans = 0;
        for(auto item : nums){
            ans |= item;
        }
        cnt = 0;
        int n = nums.size();
        Dfs(0, n, 0, nums);
        return cnt;
    }
private:
    void Dfs(int index, int n, int cur, vector<int>& nums){
        if(index >= n){
            if(cur == ans){
                ++ cnt;
            }
            return ;
        }
        Dfs(index + 1, n, cur, nums);
        cur |= nums[index];
        Dfs(index + 1, n, cur, nums);
    }
    int ans, cnt;
};

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    return 0;
}