#include <bits/stdc++.h>
using namespace std;
#define Test

const int N = 100;
int F[N];
class Solution {
public:
    int fib(int n) {
        F[0] = 0; F[1] = 1;
        for(int i = 2;i <= N - 1;i ++){
            F[i] = F[i - 1] + F[i - 2];
        }
        return F[n];
    }
};

int main(){
    return 0;
}