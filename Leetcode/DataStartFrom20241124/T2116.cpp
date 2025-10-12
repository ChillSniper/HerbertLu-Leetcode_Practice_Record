#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
#define Test

class Solution {
    public:
        bool canBeValid(string s, string locked) {
            int sz = s.size(), MinLimit = 0, MaxLimit = 0;
            for(int i = 0;i < sz;i ++){
                if(s[i] == '(' && locked[i] == '1'){
                    MinLimit ++;
                    MaxLimit ++;
                }
                else if(s[i] == ')' && locked[i] == '1'){
                    MaxLimit --;
                    MinLimit --;
                    if(MaxLimit < 0)
                        return false;
                    if(MinLimit < 0)
                        MinLimit = 1;
                }
                else{
                    MaxLimit ++;
                    MinLimit --;
                    if(MinLimit < 0)
                        MinLimit = 1;
                }
            }
            return MinLimit == 0;
        }
    };

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    string s = "(((())(((())";
    string locked = "111111010111";
    Solution example;
    if(example.canBeValid(s, locked))
        cout << "Yes";
    else 
        cout << "No";
    
    return 0;
}