#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        vector<int> text;
        int n = nums.size();
        for(int i = 1;i < n;i ++){
            if(nums[i] > nums[i - 1]) text.push_back(1);
            else if(nums[i] == nums[i - 1]) text.push_back(0);
            else text.push_back(-1);
        }
        int m = pattern.size(), cnt = 0;
        n = text.size();
        vector<int> Nxt(m + 10, 0);
        Nxt[0] = -1;
        for(int i = 0;i < m;i ++){
            int k = Nxt[i];
            while (k >= 0 && pattern[i] != pattern[k])
            {
                k = Nxt[k];
            }
            Nxt[i + 1] = ++ k;
        }
        int len = Nxt[m];
        for(int i = 0, j = 0;i < n;){
            if(j < 0 || text[i] == pattern[j]){
                i ++; j ++;
                if(j == m){
                    cnt ++;
                    j = len;
                }
            }
            if(i >= n) break;
            if(text[i] != pattern[j]){
                j = Nxt[j];
            }
        }
        // ababcdabababababababababababababababababab
        // ababab
        return cnt;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    vector<int> pattern = {1, 1};
    s.countMatchingSubarrays(nums, pattern);
    return 0;
}