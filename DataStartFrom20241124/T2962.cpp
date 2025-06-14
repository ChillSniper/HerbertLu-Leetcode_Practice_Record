#include <bits/stdc++.h>
using namespace std;
#define Test

typedef long long ll;
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        // ����е����Ǹ������ѧ����
        // byd����������ѧû��ϵ��ע�⵽���⣬�����������顣
        // ͬʱע�⵽��������û������ڲ��������ѵ���dp��
        // ��֪���ˣ���ָ���ƶ���λ��pos��Ҫ�õ�ǰ�����ڵ����ֵ��Ŀ < k�������Ļ������Ӻ�Ϊpos
        ll ans = 0;
        int i = 0, j = 0, sz = nums.size();
        int MaxNum = *max_element(nums.begin(), nums.end()), cnt_MaxNum = 0;
        while (i <= j && j < sz)
        {
            if(nums[j] == MaxNum){
                cnt_MaxNum ++;
            }
            j ++;
            if(cnt_MaxNum >= k){
                while (i < j && (cnt_MaxNum > k || (nums[i] != MaxNum && cnt_MaxNum == k)))
                {
                    if(nums[i] == MaxNum){
                        cnt_MaxNum --;
                    }
                    i ++;
                }
                ans += (i + 1);
            }
        }
        return ans;
    }
};

#define Test

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    vector<int> Num = {61,23,38,23,56,40,82,56,82,82,82,70,8,69,8,7,19,14,58,42,82,10,82,78,15,82};
    int k = 2;
    Solution s;
    cout << s.countSubarrays(Num, k);
    return 0;
}