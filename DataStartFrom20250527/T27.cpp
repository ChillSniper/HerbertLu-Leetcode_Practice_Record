#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
#define Test

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int cnt = 0;
        for(int i = 0;i < (int)nums.size();){
            if(nums[i] != val){
                ++ i;
                ++ cnt;
            }
            else{
                swap(nums[i], nums.back());
                nums.pop_back();
            }
        }
        return cnt;
    }
};

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif

    return 0;
}