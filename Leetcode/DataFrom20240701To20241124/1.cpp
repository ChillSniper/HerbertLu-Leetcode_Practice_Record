#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        vector<int> ans;
        mp[nums[0]] = 0;
        for(int i = 1;i < nums.size();i ++){
            if(mp.find(target - nums[i]) != mp.end()){
                ans.emplace_back(i);
                ans.emplace_back(mp.find(target - nums[i])->second);
                return ans;
            }
            mp[nums[i]] = i;
        }
        return ans;
    }
};

int main(){
    freopen("file.in", "r", stdin);
    freopen("file.out", "w", stdout);
    return 0;
}