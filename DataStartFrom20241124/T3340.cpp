#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define Test

class Solution {
    public:
        bool isBalanced(string num) {
            int sz = num.size(), x = 0, y = 0;
            for(int i = 0;i < sz;i ++){
                if(i % 2)
                    x += num[i];
                else
                    y += num[i];
                }
            return x == y;
        }
    };

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    return 0;
}