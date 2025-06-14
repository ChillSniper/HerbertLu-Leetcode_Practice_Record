#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;
#define Test
#define BetterWay
// #define MyWay

#ifdef BetterWay
class Solution {
public:
    int minimumSum(int n, int k) {
        if(n <= k / 2){
            return CalculateFromAtoB(1, n);
        }
        return CalculateFromAtoB(1, k / 2) + CalculateFromAtoB(k, n + k - k / 2 - 1);
        // x  - k + 1 = n - k/2
        // x = n + k / 2 - 1
    }
private:
    int CalculateFromAtoB(int a, int b){
        return (a + b) * (b - a + 1) / 2;
    }
};
#endif

#ifdef MyWay
class Solution {
public:
    int minimumSum(int n, int k) {
        unordered_set<int> st;
        int cnt = 0, sum = 0;
        for(int i = 1;cnt < n;i ++){
            if(!st.count(k - i)){
                sum += i;
                cnt ++;
                st.insert(i);
            }
        }      
        return sum;
    }
};
#endif
int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    return 0;
}