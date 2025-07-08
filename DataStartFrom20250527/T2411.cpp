#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define Test

// #define Way1
#define Way2

#ifdef Way2
// ���ģ��ϸ�ںܶ࣬������д������
class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        // ����Ļ���������Ԫ�ضԽ�ֹ���Ҷ��硣
        // ���ң�����������ͬ�����ֵ�ȵ�Ԫ�����Ҷ���������
        int n = nums.size();
        vector<int> ans(n);
        vector<pair<int, int>> rec;
        for(int i = n - 1;i >= 0;i --){
            rec.emplace_back(0, i);
            int cur_val = nums[i];
            rec[0].first |= cur_val;
            int k = 0;
            for(int j = 1;j < rec.size();j ++){
                rec[j].first |= cur_val;
                if(rec[k].first == rec[j].first){
                    rec[k].second = rec[j].second;
                }
                else{
                    rec[++ k] = rec[j];
                }
            }
            rec.resize(k + 1);
            ans[i] = rec[0].second - i + 1;
        }
        return ans;
    }
};
#endif

#ifdef Way1
// ��������
class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        // ������������ʵ���Ҳ��̫����
        // ��̫���ˣ�ע�����"|"��������ŵ��������ȼ�Ҫ�� ">" �ͣ�
        int sz = nums.size();
        vector<int> ans(sz, 1);
        for(int i = 1;i < sz;i ++){
            int x = nums[i], j = i - 1;
            while (j >= 0 && ((nums[j] | x) > nums[j]))
            {
                nums[j] = x | nums[j];
                ans[j] = i - j + 1;
                -- j;
            }
        }
        return ans;
    }
};
#endif

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif

    return 0;
}