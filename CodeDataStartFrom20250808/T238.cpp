#include <bits/stdc++.h>
using namespace std;

#define Test

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 0);
        
        result[n - 1] = nums[n - 1];
        int p = nums[n - 1];
        for (int i = n - 2;i >= 1;i --) {
            p *= nums[i];
            result[i] = p;
        }
        result[0] = result[1];
        p = nums[0];
        for (int i = 1;i < n - 1;i ++) {
            result[i] = p * result[i + 1];
            p *= nums[i];
        }
        result[n - 1] = p;
        return result;
    }
};

int main() {
    return 0;
}