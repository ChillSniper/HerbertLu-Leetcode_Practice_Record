#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        long long tmp = 1;
        for(int i = 1;i <= n;i ++){
            tmp = 2 * (2 * i - 1) * tmp / (i + 1);
        }      
        return tmp;
    }
};
