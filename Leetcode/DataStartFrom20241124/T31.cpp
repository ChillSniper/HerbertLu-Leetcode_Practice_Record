#include <bits/stdc++.h>
using namespace std;
#define Test

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
    // ���ҵ�һ��ʼ�����������ˣ��Ұ�������Ǹ����������a[i]��ʱ��û�а�[i + 1, end]�������������
    // ����һ���Ż���С�ط��������ڴӺ���ǰ���ҵ�һ�����������ʱ�̣���֮��������Ϊ�½�����
        int sz = nums.size(), pos = 0;
        for(int i = sz - 2;i >= 0;i --){
            if(nums[i] < nums[i + 1]){
                for(int j = sz - 1;j > i;j --){
                    if(nums[j] >= nums[i]){
                        swap(nums[i], nums[j]);
                        pos = i + 1;
                        goto A;
                    }
                }
            }
        }
        A:
        reverse(nums.begin() + pos, nums.end());
    }
};