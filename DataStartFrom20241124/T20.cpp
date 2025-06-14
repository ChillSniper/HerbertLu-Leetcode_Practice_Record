#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack <char> st;
        int sz = s.size();
        int num[300] = {0};
        num['('] = num[')'] = 1;
        num['['] = num[']'] = 2;
        num['{'] = num['}'] = 3;
        for(int i = 0;i < sz;i ++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.push(s[i]);
            }
            else{
                if(st.empty())
                    return false;
                char ch = st.top();
                st.pop();
                if(num[s[i]] != num[ch])
                    return false;
            }
        }
        return !s.empty();
    }
};