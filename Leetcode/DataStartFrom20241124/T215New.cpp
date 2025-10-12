#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
#define Test

class Solution {
public:
// 构建小根堆
    int findKthLargest(vector<int>& nums, int k) {
        memset(a, 0, sizeof(a));
        heap_size = 0;
        // Wrong is exist in build heap
        // so where is the error ?
        /* True Answer To Build Heap
            for(int i = 0;i < k;i ++){
                a[++ heap_size] = nums[i];
                ShiftUp(heap_size);
            }
        */

    // Another type of True Answer is below
    // 实际上，建堆的问题在于自底向上建堆，分治的思想，
    // 如果在建堆的过程中，将元素往上移动，那么实际上移下来的那个元素也是未知的，所以说往下移动即可
    // 或者可以先往上移动，再往下移动，防止元素遗漏比较
       for(int i = 0;i < k;i ++){
            a[++ heap_size] = nums[i];
       }
       for(int i = heap_size / 2;i >= 1;i --){
            ShiftDown(i);
           // ShiftUp(i);
       }
        int n = nums.size();
        for(int i = k;i < n;i ++){
            if(nums[i] > a[1]){
                swap(nums[i], a[1]);
                ShiftDown(1);
            }
        }
        return a[1];
    }
private:
    int heap_size;
    static const int N = 1e5 + 10;
    int a[N];
    void ShiftDown(int i){
        while (i <= heap_size)
        {
            int idx = i, tmp = a[i];
            if(i * 2 <= heap_size && a[i * 2] < tmp) 
                {tmp = a[i * 2]; idx = i * 2;}
            if(i * 2 + 1 <= heap_size && a[i * 2 + 1] < tmp)
                {tmp = a[i * 2 + 1]; idx = i * 2 + 1;};
            if(idx == i) break;
            swap(a[idx], a[i]);
            i = idx;
        }
    }
    void ShiftUp(int i){
        while(i / 2 >= 1 && a[i / 2] > a[i]){
            swap(a[i], a[i / 2]);
            i /= 2;
        }
    }
};

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    int n, k;
    scanf("%d%d", &n, &k);
    vector<int> num(n, 0);
    for(int i = 0;i < n;i ++)
        scanf("%d", &num[i]);
    Solution s;
    int ans = s.findKthLargest(num, k);
    printf("%d", ans);
    return 0;
}