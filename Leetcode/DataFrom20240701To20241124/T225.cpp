#include <iostream>
#include <queue>
using namespace std;

class MyStack {
public:
    MyStack() {

    }
    
    void push(int x) {
        store.push(x);
    }
    
    int pop() {
        int Length = store.size();
        Length --;
        while (Length --)
        {
            temp.push(store.front());
            store.pop();
        }
        int ans = store.front();
        store.pop();
        while (!temp.empty())
        {
            store.push(temp.front());
            temp.pop();
        }
        return ans;
    }
    
    int top() {
        return store.back();
    }
    
    bool empty() {
        return store.empty() ? true : false;
    }

private:
    queue<int> store;
    queue<int> temp;
};
