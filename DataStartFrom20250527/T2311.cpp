#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <stdint.h>
#include <math.h>
using namespace std;
#define Test
class Solution {
public:
    int longestSubsequence(string s, int k) {
        // 一开始看错题意了，这题是选取子序列，可以不连续。
        int m = __bit_width((uint32_t)k);
        int n = s.size();
        m = min(m, n);
        // n - 1 - m 
        int cnt = 0;
        for(int i = 0;i <= n - 1 - m;i ++){
            cnt += s[i] == '0' ? 1 : 0;
        }
        int sum_m_bit = 0;
        
        for(int i = n - 1;i >=  n - 1 - m + 1;i --){
            sum_m_bit += pow(2, n - 1 - i) * (s[i] - '0');
        }
        cnt += sum_m_bit <= k ? m : m - 1;
        A: 
        return cnt;
    }
};
int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    Solution s;
    s.longestSubsequence("1001010", 5);
    return 0;
}