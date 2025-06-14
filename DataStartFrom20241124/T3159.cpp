#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        int sz = nums.size();
        vector<int> position(sz + 1, 0);
        int cnt = 0;
        for(int i = 0;i < sz;i ++){
            if(nums[i] == x){
                position[++ cnt] = i;
            }
        }
        int n = queries.size();
        vector<int> ans;
        for(int i = 0;i < n;i ++){
            if(queries[i] <= cnt) ans.push_back(position[queries[i]]);
            else ans.push_back(-1); 
        }
        return ans;
    }
};