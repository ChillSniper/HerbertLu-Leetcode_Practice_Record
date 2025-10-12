#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int FirstNum = 1;
        for(int i = 0;i < nums.size() - 2;i ++){
            if(nums[i] == FirstNum) continue;
            int LeftPointer = i + 1;
            int RightPointer = nums.size() - 1;
            int storeNum = -nums[i] + 1;
            while (LeftPointer < RightPointer)
            {
                if(nums[i] + nums[LeftPointer] + nums[RightPointer] == 0){
                    if(nums[LeftPointer] != storeNum){
                        ans.push_back({nums[i], nums[LeftPointer], nums[RightPointer]});
                        FirstNum = nums[i];
                        storeNum = nums[LeftPointer];
                    }
                    LeftPointer ++;
                } else if(nums[i] + nums[LeftPointer] + nums[RightPointer] < 0){
                    LeftPointer ++;
                } else if(nums[i] + nums[LeftPointer] + nums[RightPointer] > 0){
                    RightPointer --;
                }
            }
        }
        return ans;
    }
};

int main(){
    freopen("file.in", "r", stdin);
    freopen("file.out", "w", stdout);
    int N;
    cin >> N;
    vector<int> num(N);
    for(int i = 0;i < N;i ++)
        scanf("%d", &num[i]);
    Solution s;
    vector<vector<int>> ans = s.threeSum(num);
    for(int i = 0;i < ans.size();i ++){
        for(int j = 0;j < ans[0].size();j ++){
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}