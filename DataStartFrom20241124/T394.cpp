#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
#define Test

class Solution {
    public:
    // 3[a2[c]abc24[back]aghh]
        string decodeString(string s) {
            stack<int> Num;
            stack<string> Store_String;
            int sz = s.size();
            string op = "";
            for(int i = 0;i < sz;i ++){
                if(isalpha(s[i])){
                    op += s[i];
                }
                else if(isalnum(s[i])){
                    if(op.size()){
                        Store_String.push(op);
                        op.clear();
                    }
                    int x = 0, j = i;
                    while (j < sz && isalnum(s[j]))
                    {
                        x = x * 10 + (s[j] - '0');
                        j ++;
                    }
                    i = j - 1;
                    Num.push(x);
                }
                else if(s[i] == '['){
                    Store_String.push("[");
                
                }
                else if(s[i] == ']'){
                    int cnt = Num.top();
                    Num.pop();
                    while (Store_String.size() && Store_String.top() != "[")
                    {
                        op = Store_String.top() + op;
                        Store_String.pop();
                    }
                    Store_String.pop();
                    for(int i = 0;i < cnt;i ++)
                        Store_String.push(op);
                    op.clear();
                }
            }
            if(op.size())
                Store_String.push(op);
            string ans;
            while (Store_String.size())
            {
                ans = Store_String.top() + ans;
                Store_String.pop();
            }
            return ans;
        }
    };

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    if(isalpha('1'))
        cout << "wrong";
    else 
        cout << "yes";
    return 0;
}