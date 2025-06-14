#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        n = nums.size();
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if(GetNum(mid, nums) > GetNum(mid - 1, nums) && GetNum(mid, nums) > GetNum(mid + 1, nums)) return mid;
            if(GetNum(mid, nums) > GetNum(mid - 1, nums) && GetNum(mid, nums) < GetNum(mid + 1, nums)) l = mid + 1;
            else r = mid - 1;
        }
        return -1;
    }
    long long GetNum(int idx, vector<int>& nums){
        if(idx >= 0 && idx < n) return nums[idx];
        else return -INF;
    }
private:
    int n;
    const long long INF = 2147483649;
};

int main(){
    return 0;
}