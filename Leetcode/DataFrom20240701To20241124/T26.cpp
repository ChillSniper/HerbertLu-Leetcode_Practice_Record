#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int SlowPointer = 0;
        for(int i = 1;i < nums.size();i ++){
            if(nums[i] != nums[i - 1]){
                nums[ ++SlowPointer] = nums[i];
            }
        }
        return ++SlowPointer;
    }
};
int main(){
    
    return 0;
}