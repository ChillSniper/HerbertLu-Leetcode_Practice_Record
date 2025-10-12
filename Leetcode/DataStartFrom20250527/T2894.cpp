#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
#define Test

class Solution {
public:
    int differenceOfSums(int n, int m) {
        int total_sum = (1 + n) * n / 2;
        int num2_cnt = n / m;
        int num2 = (m + num2_cnt * m) * num2_cnt / 2;
        int num1 = total_sum - num2;
        return num1 - num2;
    }
};

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif



    return 0;
}