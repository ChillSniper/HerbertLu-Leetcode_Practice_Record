#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define Test
class Solution {
public:
    int minSwaps(string s) {
        int sz = s.size(), lft_num = 0, rit_num = 0, ans = 0, i = 0, j = sz - 1;
        for(;i < j && j < sz && i >= 0;){
            while (!(s[i] == ']' && lft_num == 0) && i < sz)
            {
                if(s[i] == '[')
                    lft_num ++;
                else{
                    lft_num --;
                }
                i ++;
            }
            while (!(s[j] == '[' && rit_num == 0) && j >= 0)
            {
                if(s[j] == ']')
                    rit_num ++;
                else
                    rit_num --;
                j --;
            }
            if(i < j && i >= 0 && j < sz){
                swap(s[i], s[j]);
                i ++;
                j --;
                lft_num ++;
                rit_num ++;
                ans ++;
            }
        }        
        return ans;
    }
};
int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    string s = "][][";
    Solution e;
    cout << e.minSwaps(s);
    return 0;
}