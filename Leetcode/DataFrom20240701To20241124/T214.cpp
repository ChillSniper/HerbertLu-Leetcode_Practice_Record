#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        const int Len = s.length();
        string model = s;
        for(int i = 0, j = Len - 1;i <= j;i ++,j --){
            swap(s[i], s[j]);
        }
        const int N = 5e4 + 10;
        int next[N];
        next[0] = -1;
        for(int i = 0;i < Len - 1;i ++){
            int k = next[i];
            while (k >= 0 && model[k] != model[i])
            {
                k = next[k];
            }
            next[i + 1] = ++k;
        }
        int position;
        int i = 0, j = 0;
        while (i < Len && j < Len)
        {
            if(j < 0 || model[j] == s[i]){
                i ++; j ++;
            } else {
                j = next[j];
            }
        }
        string ans = model.substr(j, Len - j);
        reverse(ans.begin(), ans.end());
        ans += model;
        return ans;
    }
};

int main(){
    freopen("file.in", "r", stdin);
    freopen("file.out", "w", stdout);
    Solution s;
    cout << s.shortestPalindrome("abcd");
    return 0;
}