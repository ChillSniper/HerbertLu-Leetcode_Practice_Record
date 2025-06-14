#include <iostream>
#include <cstdio>
#include <vector>
//#define Way1 // 实际上初始代码中的a[]数组决定状态也是没有必要的，因为这个状态可以在自己写dfs时进行取舍
//#define BetterSolutionOfDFS
#define Way2
using namespace std;

class Solution {
public:
    #ifdef Way2
    vector<vector<int>> subsets(vector<int>& nums){
        int Len = nums.size();
        for(int i = 0;i < (1 << Len);i ++){
            arr.clear();
            for(int j = 0;j < Len;j ++){
                if(i & (1 << j)) arr.push_back(nums[j]);
            }
            ans.push_back(arr);
        }
        return ans;
    }
    #endif
    #ifdef BetterSolutionOfDFS
    vector<vector<int>> subsets(vector<int>& nums){
        DFS(nums, 0);
        return ans;
    }
    void DFS(vector<int>& nums, int k){
        if(k == nums.size()){
            ans.push_back(arr);
            return ;
        }
        DFS(nums, k + 1);
        arr.push_back(nums[k]);
        DFS(nums, k + 1);
        arr.pop_back();
    }
    #endif
    #ifdef Way1
    vector<vector<int>> subsets(vector<int>& nums) {
        int a[15] = {0};
        DFS(nums, a, 0);
        return ans;
    }
    void DFS(vector<int>& nums, int a[], int k){
        if(k == nums.size()){
            ans.push_back(arr);
            return;
        }
        if(a[k] == 0)
            DFS(nums, a, k + 1);
        a[k] = 1;
        if(a[k] == 1){
            arr.push_back(nums[k]);
            DFS(nums, a, k + 1);
            arr.pop_back();
        }
        a[k] = 0;
    }
    #endif
private:
    vector<vector<int>> ans;
    vector<int> arr;
};

int main(){
    freopen("file.in", "r", stdin);
    freopen("file.out", "w", stdout);
    vector<int> num;
    num.push_back(1);
    Solution s;
    vector<vector<int>> ans = s.subsets(num);
    return 0;
}

