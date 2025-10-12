#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> sig;
        for(int i = 0;i < s.size();i ++){
            if(sig.top() == s[i]){
                sig.pop();
            } else {
                sig.push(s[i]);
            }
        }
        string ans;
        while (!sig.empty())
        {
            ans += sig.top();
            sig.pop();
        }
        return ans;
    }
};

int main(){

    return 0;
}