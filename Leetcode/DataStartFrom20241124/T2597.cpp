#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;
#define Test

class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        // 所以应该怎么处理呢？ 如果暴力处理每一个集合的话，会导致
        // nums = {1, 2, 4, 5, 7}; // k = 3
        __k = k;
        ans = 0;
        vector<int> store;
        Dfs(nums, 0, store);
        return ans;
    }
private:
    int ans, __k;
    void Dfs(vector<int>& nums, int index, vector<int>& store){
        int sz = nums.size();
        if(index >= sz){
            if(check(store))
                ans ++;
            return ;
        }
        Dfs(nums, index + 1, store);

        store.push_back(nums[index]);
        Dfs(nums, index + 1, store);
        store.pop_back();
    }
    bool check(vector<int>& num){
        if(num.size() == 0)
            return false;
        int sz = num.size();
        for(int i = 0;i < sz;i ++){
            for(int j = i + 1;j < sz;j ++)
                if(abs(num[j] - num[i]) == __k)
                    return false;
        }
        return true;
    }
};

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif 
    Solution s;
    vector<int> num = {2, 4, 6};
    int k = 2;
    cout << s.beautifulSubsets(num, k);
    return 0;
}