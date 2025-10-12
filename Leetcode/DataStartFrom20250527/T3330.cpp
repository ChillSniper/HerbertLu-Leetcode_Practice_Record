#include <bits/stdc++.h>
using namespace std;
#define Test

class Solution {
public:
    int possibleStringCount(string word) {
        int cnt = 1;
        int sz = word.size();
        for(int i = 0;i < sz;i ++){
            int j = i;
            char cur_ch = word[i];
            while (j < sz && word[j] == cur_ch)
            {
                ++ j;
            }
            int len = j - i;
            i = j - 1;
            cnt += (len - 1);
        }
        return cnt;
    }
};

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    return 0;
}