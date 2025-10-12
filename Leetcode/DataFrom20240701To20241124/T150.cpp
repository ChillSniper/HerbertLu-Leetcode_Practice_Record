#include <iostream>
#include <stack>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> store;
        unordered_set<string> signal = {"+", "-", "*", "/"};
        for(auto i : tokens){
            if(!signal.count(i)){
                store.push(stoi(i));
            } else {
                int y = store.top();
                store.pop();
                int x = store.top();
                store.pop();
                if(i == "+") store.push(x + y);
                if(i == "-") store.push(x - y);
                if(i == "*") store.push(x * y);
                if(i == "/") store.push(x / y);
            }
        }
        return store.top();
    }
};