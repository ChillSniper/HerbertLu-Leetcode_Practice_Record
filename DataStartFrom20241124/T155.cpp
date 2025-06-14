#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;
typedef long long ll;
class MinStack {
    // 一开始没想出来，实际上就是在记录元素栈的同时
    // 维护一个同步存放最小值的栈，这样就能避免那些乱七八糟的边界处理
    private:
        stack<ll> Num, Min_Num;
        ll Num_MIN = 2147483647;
    public:
        MinStack() {
            
        }
        
        void push(int val) {
            Num_MIN = min(Num_MIN, (ll)val);
            Min_Num.push((ll)Num_MIN);
            Num.push(val);
        }
        
        void pop() {
            Num.pop();
            Min_Num.pop();
            if(Min_Num.size())
                Num_MIN = Min_Num.top();
            else 
                Num_MIN = -2147483648;
        }
        
        int top() {
            return (int)Num.top();
        }
        
        int getMin() {
            return (int)Min_Num.top();
        }
    };
    
    /**
     * Your MinStack object will be instantiated and called as such:
     * MinStack* obj = new MinStack();
     * obj->push(val);
     * obj->pop();
     * int param_3 = obj->top();
     * int param_4 = obj->getMin();
     */
int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif

    return 0;
}