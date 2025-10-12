#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
#define Test

class Solution {
public:
    char kthCharacter(int k) {
        int t = (int)log2(k);
        if((int)pow(2, t) != k){
            ++ t;
        }
        int cnt = 0;
        while (k != 1)
        {
            cnt ++;
            int s = (int) log2(k);
            if((int)pow(2, s) == k){
                -- s;
            }
            k -= (int)pow(2, s);
            -- t;
        }
        return 'a' + (cnt % 26);
    }
};

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    return 0;
}