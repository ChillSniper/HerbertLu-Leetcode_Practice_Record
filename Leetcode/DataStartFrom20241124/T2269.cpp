#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define Test

class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string s_num = to_string(num);
        int sz = s_num.size(), cnt = 0;
        for(int i = 0;i + k - 1 < sz;i ++){
            string tmp = s_num.substr(i, k);
            int t = stoi(tmp);
            if(t != 0 && num % t == 0)
                cnt ++;
        }
        return cnt;
    }
};

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    return 0;
}