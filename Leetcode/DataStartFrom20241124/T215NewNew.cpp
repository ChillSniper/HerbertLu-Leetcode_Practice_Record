#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define Test

const int N = 1e5 + 10;
int a[N], heap_size;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        heap_size = 0;
        memset(a, 0, sizeof a);
        // 构建一个小根堆
        for(int i = 0;i < k;i ++){
            a[++ heap_size] = nums[i];
        }
        BuildHeap();
        int sz = nums.size();
        for(int i = k;i < sz;i ++){
            if(nums[i] >= a[1]){
                swap(a[1], nums[i]);
                ShiftDown(1);
            }
        }
        return a[1];
    }
private:
    void ShiftUp(int i){
        while (i / 2 >= 1 && a[i] < a[i / 2])
        {
            swap(a[i], a[i / 2]);
            i /= 2;
        }
    }
    void ShiftDown(int i){
        int t = i;
        if(i * 2 <= heap_size && a[i * 2] < a[t])
            t = i * 2;
        if(i * 2 + 1 <= heap_size && a[i * 2 + 1] < a[t])
            t = i * 2 + 1;
        if(t == i)
            return ;
        swap(a[i], a[t]);
        ShiftDown(t);
    }
    void BuildHeap(){
        for(int i = heap_size / 2;i >= 1;i --){
            ShiftDown(i);
        }
    }
};

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif

    return 0;
}