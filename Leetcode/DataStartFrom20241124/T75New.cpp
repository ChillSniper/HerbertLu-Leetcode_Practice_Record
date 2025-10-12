#include <bits/stdc++.h>
using namespace std;
#define Test

class Solution {
public:
    void sortColors(vector<int>& nums) {
        // 2,0,1
        // ���ʵ���Ͼ�����·��������
        int sz = nums.size();
        int i = 0, j = 0, k = sz - 1;
        for(;j <= k;){
            // ע������ж����� jҪȡ����k
            if(nums[j] == 0){
                swap(nums[i], nums[j]);
                i ++;
                j ++;
            }
            else if(nums[j] == 1){
                j ++;
            }
            else if(nums[j] == 2){
                swap(nums[j], nums[k]);
                k --;
            }
        }
    }
};

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    vector<int> arr = {2, 0, 1};
    Solution s;
    s.sortColors(arr);

    return 0;
}