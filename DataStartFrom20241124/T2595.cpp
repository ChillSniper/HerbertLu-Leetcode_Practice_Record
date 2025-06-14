#include <iostream>
#include <cstdio>
#include <cstring>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;

#define Test

class Solution {
public:
    vector<int> evenOddBit(int n) {
        int Odd = 0, Even = 0;
        for(int i = 0;n;i ++, n >>= 1){
            if(n & 1){
                if(i % 2) Odd ++;
                else Even ++;
            }
        }
        return {Even, Odd};
    }
};

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif

    return 0;
}