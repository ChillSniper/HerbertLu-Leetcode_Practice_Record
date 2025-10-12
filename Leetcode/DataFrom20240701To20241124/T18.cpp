#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int FirstNum = 1e9 + 10;
        int Length = nums.size();
        for (int i = 0; i < Length - 3; i++) {
            if (nums[i] == FirstNum)
                continue;
            int SecondNum = 1e9 + 10;
            for (int j = i + 1; j < Length - 2; j++) {
                if (nums[j] == SecondNum)
                    continue;
                int LeftPointer = j + 1;
                int RightPointer = Length - 1;
                int thirdNUm = -1e9 - 10;
                while (LeftPointer < RightPointer) {
                    if ((long long)(nums[i] + nums[j] + nums[LeftPointer] +
                            nums[RightPointer]) ==
                        (long long)target) {
                        if (nums[LeftPointer] != thirdNUm) {
                            ans.push_back({nums[i], nums[j], nums[LeftPointer],
                                           nums[RightPointer]});
                            FirstNum = nums[i];
                            SecondNum = nums[j];
                            thirdNUm = nums[LeftPointer];
                        }
                        LeftPointer++;
                    } else if ((long long)(nums[i] + nums[j] + nums[LeftPointer] +
                                   nums[RightPointer]) >
                               (long long)target) {
                        RightPointer--;
                    } else if ((long long)(nums[i] + nums[j] + nums[LeftPointer] +
                                   nums[RightPointer]) <
                               (long long)target) {
                        LeftPointer++;
                    }
                }
            }
        }
        return ans;
    }
};

int main(){
    freopen("file.in", "r", stdin);
    freopen("file.out", "w", stdout);
    int N, target;
    cin >> N >> target;
    vector<int> data(N);
    for(int i = 0;i < N;i ++) scanf("%d", &data[i]);
    Solution s;
    vector<vector<int>> ans = s.fourSum(data, target);
    for(int i = 0;i < ans.size();i ++){
        for(int j = 0;j < ans[0].size();j ++){
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}