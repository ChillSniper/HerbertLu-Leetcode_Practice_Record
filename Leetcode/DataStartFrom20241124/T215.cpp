#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        n = nums.size();
        hp = vector<int>(k + 1, 0);
        heap_size = 0;
        for(int i = 0;i < k;i ++)
            AddNum(nums[i]);
        for(int i = k;i < n;i ++){
            if(nums[i] > hp[1]){
                hp[1] = nums[i];
                Down(1);
            }
        }
        return hp[1];
   }
private:
    int n, heap_size;
    vector<int> hp;    
    void AddNum(int x){
        hp[++ heap_size] = x;
        Up(heap_size);
    }
    void Up(int idx){
        while (idx / 2 > 0 && hp[idx / 2] > hp[idx])
        {
            swap(hp[idx / 2], hp[idx]);
            idx /= 2;
        }
        
    }
    void Down(int idx){
        int tmp = idx;
        if(idx * 2 <= heap_size && hp[idx * 2] < hp[tmp]) tmp = idx * 2;
        if(idx * 2 + 1 <= heap_size && hp[idx * 2 + 1] < hp[tmp]) tmp = idx * 2 + 1;
        if(tmp != idx){
            swap(hp[idx], hp[tmp]);
            Down(tmp);
        } 
    }
};
