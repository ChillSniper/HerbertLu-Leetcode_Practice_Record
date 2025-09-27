#include <bits/stdc++.h>
using namespace std;

#define Test

class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int i = 0, j = n - 1;
        for (int i = 0;i < n;i ++) {
            if(isalpha(s[i]) && s[i] >= 'A' && s[i] <= 'Z') {
                s[i] = (char)((int)'a' + s[i] - 'A');
            }
        }
        cout << s << endl;
        i = 0, j = n - 1;
        for (;i < j;) {
            while (i < j && !isalnum(s[i]))
            {
                ++ i;
            }
            while (j > i && !isalnum(s[j]))
            {
                -- j;
            }
            if(s[i] != s[j]){
                cout << s[i] << " " << s[j] << endl;
                return false;
            }
            -- j;
            ++ i;
        }
        return true;
    }
};

int main() {
    return 0;
}