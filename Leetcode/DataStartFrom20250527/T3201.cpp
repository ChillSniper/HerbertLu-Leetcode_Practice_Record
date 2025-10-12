#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define Test

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        // (ż��+ż��) % 2 = 0
        // (����+����) % 2 = 0
        // (����+ż��) % 2 = 1
        // �� �� �� 
        // ż ż ż
        // ż �� ż ��
        int MaxLength = 2;
        int cur_length_odd = 0, cur_length_even = 0;
        for(auto& item : nums){
            if(item % 2){
                ++ cur_length_odd;
            }
            else{
                ++ cur_length_even;
            }
        }
        MaxLength = max(max(MaxLength, cur_length_odd), max(MaxLength, cur_length_even));
        int first_num = nums[0], len = 1;
        for(int i = 1;i < nums.size();i ++){
            if(nums[i] % 2 != first_num % 2){
                len ++;
                first_num = nums[i];
            }
        }
        MaxLength = max(MaxLength, len);
        return MaxLength;
    }
};

int main(){

    return 0;
}