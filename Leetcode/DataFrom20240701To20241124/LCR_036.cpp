#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        int size = tokens.size();
        for(int i = 0;i < size;i ++){
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
                int num2 = stk.top(); stk.pop();
                int num1 = stk.top(); stk.pop();
                if(tokens[i] == "+") stk.push(num1 + num2);
                else if(tokens[i] == "-") stk.push(num1 - num2);
                else if(tokens[i] == "*") stk.push(num1 * num2);
                else if(tokens[i] == "/") stk.push(num1 / num2);
            } else stk.push(stoi(tokens[i]));
        }   
        return stk.top();
    }
};