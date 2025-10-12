#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <limits.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int sz = nums.size(), s = 0;
        vector<int> f(target + 1, 0);
        f[0] = 0;
        for(int i = 1;i <= sz;i ++){
            int l = nums[i - 1];
            s += l;
            for(int j = min(s, target);j >= l;j --){
                f[j] = max(f[j], f[j - l] + 1);
            }
        }
        return f[target];
    }
};

// ע�⣬���뻹�Ǵ���©�� �����������
// ���Ʒ���Ϊ f[i][j] = max(f[i - 1][j], f[i - 1][j - len] + 1);
// ����Ҫ���ǵ���άʱ����
// Ŀǰ���������ڣ�f[]��ʼ��Ϊ0ʱ�����������
// �ðɣ����ҵ�����������ˡ�����������ֵ�ﲻ��target���������ڶ���ѭ����target��ʼ�����ܻ���
// ����ǳ��ӣ���ʼ����ʱ����س�ʼ����INT_MIN����Ȼ������������������������ֵ�Ĵ��󴫵ݣ�