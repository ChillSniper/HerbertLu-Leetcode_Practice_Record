#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <bitset>

using namespace std;
#define Test

class Solution {
public:
    string addBinary(string a, string b) {
        // Bitwise Operations
        int len_a = a.size(), len_b = b.size();
        int len = max(len_a, len_b);
        vector<int> arr(len + 10, 0);
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int i = 0, remain = 0;
        for(;i < min(len_a, len_b);i ++){
            int curpos = (a[i] - '0') + (b[i] - '0') + remain;
            arr[i] = curpos % 2;
            remain = curpos / 2;
        }
        for(;i < len_a;i ++){
            int curpos = (a[i] - '0') + remain;
            arr[i] = curpos % 2;
            remain = curpos / 2;
        }
        for(;i < len_b;i ++){
            int curpos = (b[i] - '0') + remain;
            arr[i] = curpos % 2;
            remain = curpos / 2;
        }
        if(remain)
            arr[i ++] = remain;
        string ans;
        for(int j = 0;j < i;j ++){
            ans = (arr[j] ? "1" : "0") + ans;
        }
        return ans;
    }
};

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    return 0;
}