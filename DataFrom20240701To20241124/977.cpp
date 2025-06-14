#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans(nums.size());
        for(int i = 0, j = nums.size() - 1, Position = nums.size() - 1;i <= j;){
            if(nums[i] * nums[i] < nums[j] * nums[j]){
                ans[Position] = nums[j] * nums[j];
                Position --;
                j --;
            } else{
                ans[Position] = nums[i] * nums[i];
                Position --;
                i ++;
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
    vector<int> nums;
    for(int i = 0;i < N;i ++){
        int Temp;
        cin >> Temp;
        nums.push_back(Temp);
    }
    Solution s;
    vector<int> result = s.sortedSquares(nums);
    for(int i = 0;i < result.size();i ++){
        printf("%d ", result[i]);
    }
    return 0;
}