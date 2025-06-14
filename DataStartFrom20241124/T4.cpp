#include <bits/stdc++.h>
using namespace std;
#define Test

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // 长时间不写题真手生了，这种题得用递归来做
        int len_1 = nums1.size(), len_2 = nums2.size(), Length = len_1 + len_2, k = -1;
        if(Length % 2){
            k = Length / 2 + 1;
            return Dfs(nums1, 0, len_1 - 1,nums2, 0, len_2 - 1, k);
        }
        k = Length / 2;
        return (double)(Dfs(nums1, 0, len_1 - 1, nums2, 0, len_2 - 1, k) 
        + Dfs(nums1, 0, len_1 - 1, nums2, 0, len_2 - 1, k + 1)) / 2;
    }
private:
    int Dfs(vector<int>& nums1, int st_a, int end_a, vector<int>& nums2, int st_b, int end_b, int k){
        int len1 = end_a - st_a + 1;
        int len2 = end_b - st_b + 1;
        if(len1 > len2)
            return Dfs(nums2, st_b, end_b, nums1, st_a, end_a, k);
        if(len1 == 0)
            return nums2[st_b + k - 1];
        if(k == 1){
            return min(nums1[st_a], nums2[st_b]);
        }
        int i = min(st_a + k / 2 - 1, end_a);
        int j = min(st_b + k / 2 - 1, end_b);
        if(nums1[i] < nums2[j]){
            return Dfs(nums1, i + 1, end_a, nums2, st_b, end_b, k - (i - st_a + 1));
        }
        else 
            return Dfs(nums1, st_a, end_a, nums2, j + 1, end_b, k - (j - st_b + 1));
    }
};