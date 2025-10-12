#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define Test
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int sz = nums.size();
        vector<int> result(sz, 1);
        result[sz - 1] = nums[sz - 1];
        for(int i = sz - 2;i >= 0;i --)
            result[i] = result[i + 1] * nums[i];
        result[0] = result[1];
        for(int i = 1;i < sz - 1;i ++){
            result[i] = nums[i - 1] * result[i + 1];
            nums[i] = nums[i - 1] * nums[i];
        }    
        result[sz - 1] = nums[sz - 2];
        return result;
    }
};
int main(){
    return 0;
}