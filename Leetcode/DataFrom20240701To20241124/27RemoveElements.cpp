#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int cnt = 0;
        int Length = nums.size();
        for(int i = 0;i < Length;i ++){
            if(nums[i] == val){
                cnt ++;
                RemoveArray(nums, Length, i);
                --Length;
                i --;
            }
        }
        return nums.size() - cnt;
    }
private:
    void RemoveArray(vector<int>& nums, int Length, int Position){
        for(int i = Position;i < Length - 1;i ++)
            nums[i] = nums[i + 1];
    }
};

int main(){

    return 0;
}