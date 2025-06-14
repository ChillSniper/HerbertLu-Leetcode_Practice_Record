#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    string convertToBase7(int num) {
        stack<int> st;
        int flag = 0;
        if(num < 0){
            flag = 1;
            num = -num;
        }
        while (num)
        {
            st.push(num % 7);
            num /= 7;
        }
        if(st.size() == 0) st.push(0);
        string ans;
        if(flag) ans += "-";
        while (!st.empty())
        {
            int x = st.top(); st.pop();
            ans += to_string(x);
        }
        return ans;
    }
};