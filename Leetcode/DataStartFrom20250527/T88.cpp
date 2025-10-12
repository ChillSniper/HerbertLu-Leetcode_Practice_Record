#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;
#define Test

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> store;
        int i = 0, j = 0, index = 0;
        for(i = 0, j = 0;i < m && j < n;){
            if(nums1[i] <= nums2[j]){
                store[index ++] = nums1[i ++];
            }
            else{
                store[index ++] = nums2[j ++];
            }
        }
        while (i < m)
        {
            store[index ++] = nums1[i ++];
        }
        while (j < n)
        {
            store[index ++] = nums2[j ++];
        }
        nums1 = store;          
    }
};

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif

    return 0;
}