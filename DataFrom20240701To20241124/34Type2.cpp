#include <iostream>
#include <vector>
using namespace std;
#define Test

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int RightBorder = -2;
        int LeftBorder = -2;
        int l = 0, r = nums.size() - 1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if(nums[mid] < target){
                l = mid + 1;
                RightBorder = l;
            }else if(nums[mid] == target){
                r = mid - 1;
                l = mid + 1;
                LeftBorder = r;
                RightBorder = l;
            }else if(nums[mid] > target){
                r = mid - 1;
                LeftBorder = r;
            }
        }
        if(RightBorder == -2 || LeftBorder == -2 || RightBorder - LeftBorder < 2)
            return {-1, -1};
        return {LeftBorder + 1, RightBorder - 1};
    }
};

int main(){
    freopen("file.in", "r", stdin);
    freopen("file.out", "w", stdout);
    int N;
    cin >> N;
    vector<int> arr;
    for(int i = 0;i < N;i ++){
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    int target;
    cin >> target;
    Solution s;
    vector<int> result = s.searchRange(arr, target);
    for(int i = 0;i < result.size();i ++)
    {
        printf("%d ", result[i]);
    }
    return 0;
}