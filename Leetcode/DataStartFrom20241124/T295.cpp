#include <bits/stdc++.h>
using namespace std;
class MedianFinder {
public:
    // �����Ӧ����ά��һ���Զ���
    // �һ���ΪҪ��д�ѣ�������ˣ�ֻҪ�����ȶ���ά��������
    MedianFinder() {
        // ...
    }
    
    void addNum(int num) {
        int sz_a = MinHalf.size(), sz_b = MaxHalf.size();
        // �����������ⲽ��������
        //�������ڹ涨��Ҫ����sz_b = sz_a ���� sz_b = sz_a + 1
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
    priority_queue<int> MinHalf;// �󶥶ѱ����С��һ��
    priority_queue<int, vector<int>, greater<int>> MaxHalf;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */