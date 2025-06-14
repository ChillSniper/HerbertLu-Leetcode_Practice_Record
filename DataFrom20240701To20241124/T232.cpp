#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class MyQueue {
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        IN.push(x);
    }
    
    int pop() {
        int ans = peek();
        Out.pop();
        return ans;
    }
    
    int peek() {
        if(Out.empty()){
            while(!IN.empty()){
                Out.push(IN.top());
                IN.pop();
            }
        }
        return Out.top();
    }
    
    bool empty() {
        return IN.empty() && Out.empty() ? true : false;
    }
private:
    stack<int> IN;
    stack<int> Out;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main(){
    
    return 0;
}