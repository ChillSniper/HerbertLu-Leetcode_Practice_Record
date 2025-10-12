#include <iostream>
#include <cstdio>
#include <stack>
#include <unordered_map>
using namespace std;
#define Test
#define MySolution
//#define BetterSolution

class Solution {
public:
    #ifdef BetterSolution
    // pay attention to the requirement of the question: 
    //don't have the parentheses!!! so my solution is too complex
    #endif
    #ifdef MySolution
    int calculate(string s) {
        unordered_map<char, int> mp;
        mp['*'] = 2; mp['/'] = 2; mp['+'] = 1; mp['-'] = 1; mp['('] = mp[')'] = 0;
        stack<int> num;
        stack<char> ops;
        for(int i = 0;i < s.length();i ++){
            if(s[i] == ' '){
                continue;
            } else if(s[i] == '('){
                ops.push(s[i]);
            } else if(s[i] == ')'){
                while (ops.top() != '(')
                {
                    DealNum(num, ops);
                }
                if(ops.top() == '(') ops.pop();       
            } else if(isdigit(s[i])){
                int tmp = 0, j = i;
                while (j < s.length() && isdigit(s[j]))
                {
                    tmp = tmp * 10 + (s[j] - '0');
                    j ++;
                }
                i = j - 1;
                num.push(tmp);
            } else{
                if(!ops.empty() && mp[s[i]] <= mp[ops.top()]){
                    DealNum(num, ops);
                } 
                ops.push(s[i]);
            }
        }
        while (!ops.empty() && ops.top() != '(')
        {
            DealNum(num, ops);
        }
        return num.top();
    }
    #endif
    void DealNum(stack<int>& Num, stack<char>& ops){
        int num2 = Num.top();
        Num.pop();
        int num1 = Num.top();
        Num.pop();
        switch (ops.top())
        {
        case '+': Num.push(num1 + num2);
            break;
        case '-': Num.push(num1 - num2);
            break;
        case '*': Num.push(num1 * num2);
            break;
        case '/': Num.push(num1 / num2);
            break; 
        default:
            break;
        }
        ops.pop();
    }
};

int main(){
    #ifdef Test
    freopen("file.in", "r", stdin);
    freopen("file.out", "w", stdout);
    #endif
    string s;
    getline(cin, s);
    Solution fk;
    cout << fk.calculate(s);
    return 0;
}