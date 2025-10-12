#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define Test

class Solution {
    public:
        string breakPalindrome(string palindrome) {
            // abcbbcba
            // aacbbcba
            int sz = palindrome.size();
            string ans = "";
            for(int j = 0;j < 26;j ++){
                for(int i = 0;i < sz;i ++){
                    char ch = 'a' + j;
                    char ori = palindrome[i];
                    palindrome[i] = ch;
                    if(check(palindrome)){
                        if(!ans.size() || ans.compare(palindrome) > 0){
                            ans = palindrome;
                        }
                    }
                    palindrome[i] = ori;
                }
            }
            return ans;
        }
    private:
        bool check(string& s){
            int sz = s.size();
            for(int i = 0, j = sz - 1;i < j;i ++, j --){
                if(s[i] != s[j])
                    return true;
            }
            return false;
        }
    };

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    string t = "abccba";
    Solution s;
    cout << s.breakPalindrome(t);
    return 0;
}