#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        EraseMultipleElements(nums);
        // for(int i = 0;i < nums.size();i ++) cout << nums[i];
        // return {{1}};
        vector<vector<int>> ans;
        vector<int> arr;
        int len = nums.size();
        for(int j = 0;j < (1 << len);j ++){
            arr.clear();
            for(int i = 0;i < len;i ++){
                if(j && (1 << i)) arr.push_back(nums[i]);
            }
            ans.push_back(arr);
        }
        return ans;
    }
    void EraseMultipleElements(vector<int>& nums){
        int len = nums.size();
        sort(nums.begin(), nums.end());
        int sl = 1, fs = 1;
        for(;fs < len && sl <= fs;){
            if(nums[fs] != nums[fs - 1]){
                nums[sl ++] = nums[fs ++];
            } else{
                fs ++;
            }
        }
        nums.erase(nums.begin() + sl, nums.end());
    }
};

int main(){
    freopen("file.in", "r", stdin);
    freopen("file.out", "w", stdout);
    vector<int> num;
    num.push_back(1); num.push_back(1); num.push_back(2); num.push_back(2);
    Solution s;
    s.subsetsWithDup(num);
    return 0;
}