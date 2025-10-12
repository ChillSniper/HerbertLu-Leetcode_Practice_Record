#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        vector<int> IsPrime(n + 1, 1);
        int cnt = 0;
        for(int i = 2;i < n;i ++){
            if(IsPrime[i]){
                cnt ++;
                if((long long)i * i < n){
                    for(int j = i *i;j < n;j += i){
                        IsPrime[j] = 0;
                    }
                }
            }
        }
        return cnt;
    }
};