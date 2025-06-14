#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int SlowPosition, FastPosition;
        SlowPosition = 0;
        for(int i = 0;i < nums.size();i ++){
            if(nums[i] != val){
                nums[SlowPosition ++] = nums[i];
            }
        }
        return SlowPosition;
    }
};
int main(){

    return 0;
}