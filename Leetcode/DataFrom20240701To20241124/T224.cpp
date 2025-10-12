#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
#define Test
//#define Way1TwoStack
#define Way2DeleteBrackets

class Solution {
public:
    #ifdef Way1TwoStack
    int calculate(string s){
        stack<int> Num;
        stack<char> Ops;
        DeleteTheFuckingBlank(s);
        Num.push(0);
        for(int i = 0;i < s.length();i ++){
            if(s[i] == '(') Ops.push('(');
            else if(s[i] == ')'){
                while (Ops.top() != '(')
                {
                    DealTwoNum(Num, Ops);
                }
                if(Ops.top() == '(') Ops.pop(); 
            } 
            else if(s[i] == '+' || s[i] == '-'){
                if(!Ops.empty() && (Ops.top() == '+' || Ops.top() == '-')) DealTwoNum(Num, Ops);
                if(i && (s[i - 1] == '(' || s[i - 1] == '+' || s[i - 1] == '-')) Num.push(0);
                Ops.push(s[i]);                
            }
            else if(isdigit(s[i])){
                int tmp = 0, j = i;
                while (j < s.length() && isdigit(s[j]))
                {
                    tmp = tmp * 10 + (s[j] - '0');
                    j ++;
                }
                i = j - 1;
                Num.push(tmp);
            }
        }
        while (!Ops.empty()) DealTwoNum(Num, Ops);
        return Num.top();
    }   
    #endif
    #ifdef Way2DeleteBrackets
    int calculate(string s){
        int res = 0;
        int sign = 1;
        stack<int> ops;
        ops.push(1);
        for(int i = 0;i < s.length();i ++){
            if(s[i] == '+'){
                sign = 1 * ops.top(); 
            } else if(s[i] == '-'){
                sign = -1 * ops.top();
            } else if(s[i] == '('){
                ops.push(sign);
            } else if(s[i] == ')'){
                ops.pop();
            } else if(s[i] == ' '){
                continue;
            } else if(isdigit(s[i])){
                int tmp = 0, j = i;
                while (j < s.length() && isdigit(s[j]))
                {
                    tmp = tmp * 10 + (s[j] - '0');
                    j ++;
                }
                i = j - 1;
                res = res + sign * tmp; 
            }
        }
        return res;
    }
    #endif
private:
    void DeleteTheFuckingBlank(string& s){
        int pos = s.find(" ");
        while (pos != -1)
        {
            s.replace(pos, 1, "");
            pos = s.find(" ");
        }
    }
    void DealTwoNum(stack<int>& Num, stack<char>& Ops){
        int Num2 = Num.top();
        Num.pop();
        int Num1 = Num.top();
        Num.pop();
        if(Ops.top() == '+') Num.push(Num1 + Num2);
        else if(Ops.top() == '-') Num.push(Num1 - Num2);
        Ops.pop();
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

