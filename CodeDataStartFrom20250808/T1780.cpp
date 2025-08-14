#include <bits/stdc++.h>
using namespace std;

#define Test

typedef long long ll;
class Solution {
public:
    bool checkPowersOfThree(int n) {
        while (n)
        {
            int x = n % 3;
            if(x == 2)
                return false;
            n /= 3;
        }
        
        return true;
    }
};

int main() {
    #ifdef Test
    #endif
    return 0;
}