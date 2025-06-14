#include <bits/stdc++.h>
using namespace std;

#define Print
// #define MyWay
#define BetterWay

#ifdef BetterWay
class Solution {
    public:
        int subsetXORSum(vector<int>& nums) {
            int _ = 0, sz = nums.size();
            for(int i = 0;i < sz;i ++){
                _ = _ | nums[i]; 
            }
            return _ * (int)pow(2, sz - 1);
        }
    };
#endif

#ifdef MyWay
class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        ans = 0;
        vector<int> cur;
        Dfs(nums, 0, cur);
        return ans;
    }
private:
    int ans;
    void Dfs(vector<int>& num, int pos, vector<int>& cur){
        int sz = num.size();
        if(pos >= sz){
            ans += GetXor(cur);
            return ;
        }
        int x = num[pos];
        cur.push_back(x);
        // ans += GetXor(cur);
        Dfs(num, pos + 1, cur);
        cur.pop_back();
        // ans += GetXor(cur);
        Dfs(num, pos + 1, cur);
    }
    int GetXor(vector<int>& cur){
        int x = 0, sz = cur.size();
        #ifdef Print
        printf("{");
        for(int i = 0;i < sz;i ++){
            printf("%d, ", cur[i]);
        }
        printf("}\n");
        #endif
        for(int i = 0;i < sz;i ++){
            x = x xor cur[i];
        }
        return x;
    }
};
#endif
#define Test
int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    vector<int> num = {1, 3};
    Solution s;
    s.subsetXORSum(num);
    return 0;
}