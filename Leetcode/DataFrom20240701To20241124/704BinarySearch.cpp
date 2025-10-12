#include <iostream>
#include <vector>
using namespace std;
#define Test

class Solution {
public:
    int search(vector<int>& nums, int target) {
        // []
        /*
        int l = 0, r = nums.size() - 1;
        while(l <= r){
            int mid = (l + r) >> 1;
            if(nums[mid] > target){
                r = mid - 1;
            } else if(nums[mid] < target){
                l = mid + 1;
            } else if(nums[mid] == target){
                return mid;
            }
        }
        return -1;
        */
       
       // [)
       int l = 0, r = nums.size();
       while (l < r)
       {
            int mid = (l + r) >> 1;
            if(nums[mid] > target){
                r = mid;
            }else if(nums[mid] < target){
                l = mid + 1;
            }else {
                return mid;
            }
       }
       return l;
    }
};
int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    int N;
    cin >> N;
    vector<int> num;
    for(int i = 0;i < N;i ++){
        int temp;
        cin >> temp;
        num.push_back(temp);
    }
    int target;
    cin >> target;
    Solution s;
    cout << s.search(num, target);
    return 0;
}
