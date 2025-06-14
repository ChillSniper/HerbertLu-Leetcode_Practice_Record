#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;
#define Test

class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        // ��������sortһ��
        sort(nums.begin(), nums.end());
        // ���ѡȡ��ֵ��ʱ���е�С����
        // ѡȡp�����ԣ�Ҳ����Ҫѡȡ p * 2 ��item
        // ���̰���㷨������ôд�أ�
        // ��ʵֱ�Ӱ�ÿ�����ڵļ����ȥ�������ˣ������������ڣ����ܻ������ظ�ȡ��
        // �ҷ��ˣ�������־�Ȼ�ǴӲ�ֵ�ķ�Χ�Ƕȳ�����
        int l = 0, r = 0;
        int sz = nums.size();
        for(int i = 1;i < sz;i ++){
            r = max(r, abs(nums[i] - nums[i - 1]));
        }
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            bool flag = Enable(nums, p, mid);
            if(flag){
                r = mid;
            }
            else{
                l = mid + 1;
            }
        }
        return r;
    }
private:
    bool Enable(vector<int>& nums, int p, int max_val){
        // if (b - a > max_val, we thought next.)
        int cnt = 0;
        int sz = nums.size();
        for(int i = 0;i < sz - 1;){
            int nxt_val = nums[i + 1];
            int cur_val = nums[i];
            if(abs(cur_val - nxt_val) <= max_val){
                ++ cnt;
                i += 2;
            }
            else{
                i += 1;
            }
        }
        return cnt >= p;
    }
};

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif

    return 0;
}