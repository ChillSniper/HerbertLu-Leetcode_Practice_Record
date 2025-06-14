#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
#define Test

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        ans.push_back(FindFirstPos(nums, target));
        ans.push_back(FindLastPos(nums, target));
        return ans;
    }
private:
    int FindFirstPos(vector<int>& num, int t){
        int mid, n = num.size(), l = 0, r = n - 1;
        while (l <= r)
        {
            mid = l + (r - l) / 2;
            if(num[mid] >= t) r = mid - 1; // 注意此处的取等和不等号的方向！！！
            else l = mid + 1;
        }
        if(l >= 0 && l < n && num[l] == t) return l;
        return -1;
    }
    int FindLastPos(vector<int>& num, int t){
        int mid, n = num.size(), l = 0, r = n - 1;
        while (l <= r)
        {
            mid = l + (r - l) / 2;
            if(num[mid] > t) r = mid - 1;
            else l = mid + 1;
        }
        if(r >= 0 && r < n && num[r] == t) return r;
        return -1;
    }
};

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif

    return 0;
}