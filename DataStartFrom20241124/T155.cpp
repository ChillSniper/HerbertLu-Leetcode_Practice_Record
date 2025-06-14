#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;
typedef long long ll;
class MinStack {
    // һ��ʼû�������ʵ���Ͼ����ڼ�¼Ԫ��ջ��ͬʱ
    // ά��һ��ͬ�������Сֵ��ջ���������ܱ�����Щ���߰���ı߽紦��
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