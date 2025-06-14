#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

#define Test

class Solution {
    public:
        vector<string> generateParenthesis(int n) {
            string cur = "";
            Dfs(n, 0, cur, 0);
            return ans;
        }
    private:
        vector<string> ans;
        void Dfs(int n, int remain, string cur, int cnt){
            if(remain == n - cnt){
                for(int j = 1;j <= remain;j ++){
                    cur = cur + ')';
                }
                ans.push_back(cur);
                cnt = n;
                return ;
            }
            if(cnt == n)
                return ;
            if(remain == 0){
                string x = cur + '(';
                remain ++;
                Dfs(n, remain, x, cnt);
            }
            else{
                string x = cur + '(';
                Dfs(n, remain + 1, x, cnt);
                x = cur + ')';
                Dfs(n, remain - 1, x, cnt + 1);
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