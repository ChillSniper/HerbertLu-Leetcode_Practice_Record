#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
class Solution {
public:
    long long splitArray(vector<int>& nums) {
        ll sum_a = 0, sum_b = 0;
        for(int i = 0;i < nums.size();i ++){
            if(IsPrime(i)){
                sum_a += nums[i];
            }
            else{
                sum_b += nums[i];
            }
        }
        return abs(sum_a - sum_b);
    }
private:
    bool IsPrime(int x){
        if(x <= 1){
            return false;
        }
        for(int i = 2;i * i <= x;i ++){
            if(x % i == 0){
                return false;
            }
        }
        return true;
    }
};