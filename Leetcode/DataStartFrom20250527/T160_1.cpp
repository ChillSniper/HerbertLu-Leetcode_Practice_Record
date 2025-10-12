#include <bits/stdc++.h>
using namespace std;
#define Test
class Solution {
public:
    string concatHex36(int n) {
        string s1 = "", s2 = "";
        int n_record = n;
        while (n_record > 0)
        {
            int t = n_record % 16;
            n_record /= 16;
            char ch = (t < 10 ? '0' + t : 'A' + t - 10);
            s1 = s1 + ch;
        }
        n_record = n;
        while (n_record > 0)
        {
            int t = n_record % 36;
            n_record /= 16;
            char ch = (t < 10 ? '0' + t : 'A' + t - 10);
            s2 = s2 + ch;
        }
        return s1 + s2;
    }
};
int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    return 0;
}