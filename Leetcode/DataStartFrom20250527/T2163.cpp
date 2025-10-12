#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define Test

class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        // 左半边尽可能小，右半边尽可能大，由此差值最小
        priority_queue<int, vector<int>, greater<int>> Smallest;
        priority_queue<int> Bigest;
        int sz = nums.size();
        vector<int> Pre(sz, 0);
        int n = sz / 3;
        Pre[0] = nums[0];
        Bigest.push(nums[0]);
        for(int i = 1;i < n;i ++){
            Pre[i] = Pre[i - 1] + nums[i];
            Bigest.push(nums[i]);
        }
        for(int i = n;i < sz;i ++){
            int x = nums[i];
            if(x < Bigest.top()){
                int t = Bigest.top();
                Bigest.pop();
                Bigest.push(x);
                Pre[i] = Pre[i - 1] - t + x;
            }
            else{
                Pre[i] = Pre[i - 1];
            }
        }
        vector<int> Suf(sz, 0);
        Suf[sz - 1] = nums[sz - 1];
        Smallest.push(nums[sz - 1]);
        for(int i = sz - 2;i >= 2 * n;i --){
            Suf[i] = Suf[i + 1] + nums[i];
            Smallest.push(nums[i]);
        }
        for(int i = 2 * n - 1;i >= 0;i --){
            int x = nums[i];
            if(x > Smallest.top()){
                int t = Smallest.top();
                Smallest.pop();
                Smallest.push(x);
                Suf[i] = Suf[i + 1] - t + x;
            }
            else{
                Suf[i] = Suf[i + 1];
            }
        }
        int ans = Pre[n - 1] - Suf[n];
        for(int i = n;i <= 2 * n - 1;i ++){
            ans = min(ans, Pre[i] - Suf[i + 1]);
        }
        return ans;
    }
};

int main(){

    return 0;
}