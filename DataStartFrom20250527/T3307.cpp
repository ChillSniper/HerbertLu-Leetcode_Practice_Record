#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
#define Test
typedef long long ll;
class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int t = log2(k);
        if((ll)pow(2, t) != k){
            ++ t;
        }
        int cnt = 0;
        while (k != 1)
        {
            int s = log2(k);
            if((ll)pow(2, s) == k){
                -- s;
            }
            if(operations[s] == 1){
                ++ cnt;
            }
            k -= pow(2, s);
        }
        return 'a' + cnt % 26;
    }
};
int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    return 0;
}