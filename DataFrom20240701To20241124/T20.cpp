#include <bits/stdc++.h>
using namespace std;
#define Test

class Solution {
public:
    bool isValid(string s) {
        char Pir[200];
        Pir[')'] = '('; Pir[']'] = '['; Pir['}'] = '{';
        stack<char> Sig;
        for(int i = 0;i < s.length();i ++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                Sig.push(s[i]);
            } else {
                if(!Sig.empty() && Pir[s[i]] == Sig.top()){
                    Sig.pop(); continue;
                } else return false;
            }
        }
        if(Sig.empty())
        return true;
        else return false;
    }   
};

int main(){
    #ifdef Test
    freopen("file.in", "r", stdin);
    freopen("file.out", "w", stdout);
    #endif
    return 0;
}