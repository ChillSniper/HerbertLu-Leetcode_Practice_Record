#include <iostream>
#include <vector>
using namespace std;
#define Test
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int LeftBorder = GetLeftBorder(nums, target);
        int RightBorder = GetRightBorder(nums, target);
        if(RightBorder - LeftBorder < 2 || RightBorder == -2 || LeftBorder == -2) 
            return {-1, -1};
        return {LeftBorder + 1, RightBorder - 1};
    }
private:
    int GetLeftBorder(vector<int>& nums, int target){
        int l = 0, r = nums.size() - 1;
        int RecordLeft = -2;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if(nums[mid] < target){
                l = mid + 1;
            }else if(nums[mid] >= target){
                r = mid - 1;
                RecordLeft = r;
            }
        }
        return RecordLeft;
    }
    int GetRightBorder(vector<int>& nums, int target){
        int l = 0, r = nums.size() - 1;
        int RecordRight = -2;
        while (l <= r){
            int mid = (l + r) >> 1;
            if(nums[mid] <= target){
                l = mid + 1;
                RecordRight = l;
            }else if(nums[mid] > target){
                r = mid - 1;
            }
        }
        return RecordRight;
    }
};

int main(){
    #ifdef Test
    freopen("file.in", "r", stdin);
    freopen("file.out", "w", stdout);
    #endif

    return 0;
}