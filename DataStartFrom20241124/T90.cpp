#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        n = nums.size();
        vector<int> cur;
        used = vector<int>(n, false);
        Dfs(0, nums, cur);
        return ans;
    }
private:
    int n;
    vector<vector<int>> ans;
    vector<int> used;
    void Dfs(int index, vector<int>& nums, vector<int>& cur){
        // ʵ���ϣ��������ظ�Ԫ�ص�ѡȡ��Ҫ��¼��ǰֵ�Ƿ���ʹ���Ҳ����˵�����ڵ�ǰ��֦���͵�ǰ���㣬Ҫ�������۹�ȥ
        ans.push_back(cur);
        for(int i = index;i < n;i ++){
            if(i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) continue;
            cur.push_back(nums[i]);
            used[i] = true;
            Dfs(i + 1, nums, cur);
            used[i] = false;
            cur.pop_back();
        }
    }
};