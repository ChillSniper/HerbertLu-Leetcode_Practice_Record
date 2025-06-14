#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

#define Test

class Solution {
public:
    int longestValidParentheses(string s) {
        //  �������ҿ�������������±�����
        // ���Ե��׸���ô����
        // dp[i] means the longest string at cur pos to before
        //  ���� '(' dp[i] = 0
        //  ���� ')' 
        // ��ǰһ��Ϊ'('
        // dp[i] = dp[i - 2] + 2
        // ���� ��ǰһ��Ϊ')'
        // Ѱ�ҵ���ǰλ�õ�ǰһ���Ӵ� sub_s
        // 
        // ���������ʽ "()()())"
        // len of sub_s = dp[i - 1]
        // i - 1 - x + 1 = dp[i - 1]
        // x = i - dp[i - 1]
        // ���Լ���λ��pos = x - 1 = i - 1 - dp[i - 1]
        // ��� = '(' dp[i] = dp[i - 1] + 2 + dp[pos - 1];
        // else dp[i] = 0
        //  then calculate the max element of the dp array
        int sz = s.size();
        s = " " + s;
        vector<int> f(sz + 1, 0);
        int MaxAns = 0;
        for(int i = 1;i <= sz;i ++){
            char ch = s[i];
            if(s[i] == '(')
                f[i] = 0;
            else{
                char bfch = s[i - 1];
                if(bfch == '(')
                    f[i] = f[i - 2] + 2;
                else if(bfch == ')'){
                    int pos = i - 1 - f[i - 1];
                    if(pos <= 0 || s[pos] == ')')
                        f[i] = 0;
                    else if(s[pos] == '(')
                        f[i] = f[i - 1] + 2 + f[pos - 1];
                }
            }
            MaxAns = max(MaxAns, f[i]);
            printf("Test : f[%d] = %d\n", i, f[i]);
        }
        return MaxAns;
    }
};

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    // string s = ")(()(()(((())(((((()()))((((()()(()()())())())()))()()()())(())()()(((()))))()((()))(((())()((()()())((())))(())))())((()())()()((()((())))))((()(((((()((()))(()()(())))((()))()))())";
    string s = "(()())";
    Solution fk;
    cout << fk.longestValidParentheses(s);

    return 0;
}