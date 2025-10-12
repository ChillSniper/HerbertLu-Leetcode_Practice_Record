#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int res = 0, cur = 0;
        mp[cur] = 1;
        for(int i = 0;i < nums.size();i ++){
            cur += nums[i];
            if(mp.count(cur - k))
                res += mp[cur - k];
            mp[cur] ++;
        }  
        return res;
    }
};
int main(){

    return 0;
}