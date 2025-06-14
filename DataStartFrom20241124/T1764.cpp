#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int n = groups.size(), idx = 0;
        for(int i = 0;i < n;i ++){
            if(!Kmp(groups[i], nums, idx)) return false;
        }
        return true;
    }
    bool Kmp(vector<int>&text, vector<int>& nums, int& idx){
        int n = text.size();
        vector<int> Nxt(n + 10, 0);
        Nxt[0] = -1;
        for(int i = 0;i < n;i ++){
            int k = Nxt[i];
            while (k >= 0 && text[i] != text[k])
            {
                k = Nxt[k];
            }
            Nxt[i + 1] = ++ k;
        }
        int m = nums.size();
        for(int j = 0;idx < m;){
            if(j < 0 || nums[idx] == text[j]){
                idx ++; j ++;
                if(j == n) return true;
                if(idx == m) return false;
            }
            if(text[j] != nums[idx]){
                j = Nxt[j];
            }
        }
        return false;
    }
};

int main(){
    Solution s;
    vector<vector<int>> groups = {{1, 2, 3}, {3, 4}};
    vector<int> nums = {7,7,1,2,3,4,7,7};
    s.canChoose(groups, nums);
    return 0;
}