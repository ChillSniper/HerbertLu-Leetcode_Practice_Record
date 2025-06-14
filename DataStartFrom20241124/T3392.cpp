#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;

typedef long long ll;
class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        unordered_set<ll> st;
        int sz = nums.size(), ans = 0;
        for(int i = 0;i < sz;i ++){
            for(int j = i + 1;j < sz;j ++){
                if(!(nums[j] % 2)){
                    int target = nums[j] / 2 - nums[i];
                    int x = Calculate(j + 1, sz - 1, target, nums);
                    if(x){
                        // cout << "i = " << i << "; j = " << j << endl;
                        ll value = (nums[i] + 100) >> 16 + (nums[j] + 100)>> 8 + (target + 100);
                        if(!st.count(value)){
                            st.insert(value);
                            ans += x;
                        }
                    }
                }
            }
        }
        return ans;
    }
private:
    int Calculate(int l, int r, int target, vector<int>& num){
        int sz = num.size();
        if(l > sz || r < 0 || l > r){
            return 0;
        }
        int ans = 0;
        for(int i = l;i <= r;i ++){
            if(num[i] == target){
                ++ ans;
            }
        }
        return ans;
    }
};

int main(){
    vector<int> arr = {1, 2, 1, 4, 1};
    Solution s;
    cout << s.countSubarrays(arr);
    return 0;
}