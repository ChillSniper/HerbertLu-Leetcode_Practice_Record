#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define Test

class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        int a[100] = {0};
        for(int i = lowLimit;i <= highLimit;i ++){
            string s = to_string(i);
            int sum = 0, sz = s.size();
            for(int i = 0;i < sz;i ++) sum += (s[i] - '0');
            a[sum] ++;
        }
        int Max = 0;
        for(int i = 0;i < 100;i ++) Max = max(Max, a[i]);
        return Max;
    }
};

int main(){

    return 0;
}