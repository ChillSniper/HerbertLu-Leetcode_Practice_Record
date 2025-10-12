#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> sig;
        for(int i = 0;i < s.size();i ++){
            if(s[i] == '{' || s[i] == '(' || s[i] == '['){
                sig.push(s[i]);
            } else {
                if(sig.empty()) return false;
                else {
                    switch (s[i])
                    {
                    case '}':
                        if(sig.top() != '{') return false;
                        else sig.pop();
                        break;
                    case ')':
                        if(sig.top() != '(') return false;
                        else sig.pop();
                        break;
                    case ']':
                        if(sig.top() != '[') return false;
                        else sig.pop();
                        break;
                    default:
                        break;
                    }
                }
            }
        }
        return true;
    }
};