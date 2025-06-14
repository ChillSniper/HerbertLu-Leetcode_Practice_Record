#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

#define Test

class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        // ������ ���ֵ����Сֵ ���⣬���Կ��ǲ��ö��ֵ�˼�����
        // ͬʱ����ע�⵽��ֱ����maxOperationsȥ���⣬�������֣�����Ӧ�����ö�ÿ��nums[i]�и�ɲ�����һ����ֵx
        // �ķ�ʽͳ��SumOfOperation��Ȼ����maxOperations�Ƚ�
        int sz = nums.size();
        int l = 1, r = *max_element(nums.begin(), nums.end());
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if(CalculateNum(nums, mid) <= maxOperations){
                r = mid;
            } 
            else 
                l = mid + 1;
        }
        return l;
    }
private:
    int CalculateNum(vector<int>& nums, int x){
        int sum = 0, sz = nums.size();
        for(int i = 0;i < sz;i ++)
            sum += (nums[i] - 1) / x;
        return sum;
    }
};

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    return 0;
}