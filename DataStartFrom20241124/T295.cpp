#include <bits/stdc++.h>
using namespace std;
class MedianFinder {
public:
    // 这道题应该是维护一个对顶堆
    // 我还以为要手写堆，差点忘了，只要用优先队列维护就行了
    MedianFinder() {
        // ...
    }
    
    void addNum(int num) {
        int sz_a = MinHalf.size(), sz_b = MaxHalf.size();
        // 问题就在添加这步操作上面
        //我们现在规定，要控制sz_b = sz_a 或者 sz_b = sz_a + 1
        if(sz_b == sz_a){
            MinHalf.push(num);
            int x = MinHalf.top(); MinHalf.pop();
            MaxHalf.push(x);
        }
        else{
            MaxHalf.push(num);
            int x = MaxHalf.top(); MaxHalf.pop();
            MinHalf.push(x);
        }
    }
    
    double findMedian() {
        int sz_a = MinHalf.size(), sz_b = MaxHalf.size();
        if(sz_a < sz_b){
            return MaxHalf.top();
        }
        else{
            double a = MinHalf.top();
            double b = MaxHalf.top();
            return (a + b) / 2;
        }
        return -1;
    }
private:
    priority_queue<int> MinHalf;// 大顶堆保存较小的一般
    priority_queue<int, vector<int>, greater<int>> MaxHalf;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */