#include <bits/stdc++.h>
using namespace std;
#define Test
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        vector<int> ans;
        for(auto i: nums1) mp[i] ++;
        for(auto i: nums2){
            if(mp.count(i)){
                ans.push_back(i);
                mp[i] --;
                if(mp[i] == 0)
                    mp.erase(i);
            }
        }
        return ans;
    }
};

int main(){
    freopen("file.in", "r", stdin);
    freopen("file.out", "w", stdout);
    int Length1, Length2;
    cin >> Length1 >> Length2;
    vector<int> arr1(Length1), arr2(Length2);
    for(int i = 0;i < Length1;i ++)
        scanf("%d", &arr1[i]);
    for(int i = 0;i < Length2 ;i ++){
        scanf("%d", &arr2[i]);
    }
    Solution s;
    vector<int> ans = s.intersect(arr1, arr2);
    for(int i = 0;i < ans.size();i ++) cout << ans[i];
    return 0;
}