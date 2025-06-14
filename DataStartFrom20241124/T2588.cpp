#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
#define Test

class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        // ������ôӺ������� ��
        // û�����ֵ��κ�˼·
        // ������Ҫͳ��Ŀ��������ĸ���
        // ������˼·���� ����ת��Ϊ�˶����ƣ��������֮����ܺ�Ϊ0
        // ��ô�����ת��Ϊ ��ǰ���ֵ���ǰ���ֵ��ȵ�ֵ���ܺ�
        // ��Ȼ����һ�ֺ���ֵ���� s[i] = s[i - 1] = x;
        // �����ζ�� x[i] = 0;
        // ��Ȼ��Ҳ���Լ���ȥ�԰�....
        unordered_map<int, int> ump;
        ump[0] = 1;
        long long ans = 0;
        int sz = nums.size(), cur = 0;
        for(int i = 0;i < sz;i ++){
            cur = cur ^ nums[i];
            if(ump.count(cur))
                ans += ump[cur];
            ++ ump[cur];
        }
        return ans;
    }

};