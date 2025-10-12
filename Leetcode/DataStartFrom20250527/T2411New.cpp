#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define Test

class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        vector<pair<int, int>> record;
        for (int i = n - 1;i >= 0;i --) {
            int cur_val = nums[i];
            record.emplace_back(i, 0);
            int k = 0;
            record[0].second |= cur_val;
            for (int j = 1;j < record.size();j ++) {
                record[j].second |= cur_val;
                if(record[k].second == record[j].second){
                    record[k].first = record[j].first;
                }
                else{
                    record[++ k] = record[j];
                }
            }
            record.resize(k + 1);
            ans[i] = record[0].first - i + 1;
        }
        return ans;
    }
};

int main(){

    return 0;
}