#include <iostream>
#include <cstdio>
#include <stack>
#include <vector>
using namespace std;
#define Test

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> num;
        for(int i = 0, j = 0;i < popped.size();i ++){
            while (num.empty() || !num.empty() && num.top() != popped[i])
            {
                if(j == pushed.size()) return false;
                num.push(pushed[j]);
                j ++;
            }
            // 1 2 3 4 5
            // 4 3 5 1 2
            num.pop();
        }
        return true;
    }
};

int main(){
    #ifdef Test
    freopen("file.in", "r", stdin);
    freopen("file.out", "w", stdout);
    #endif
    return 0;
}