#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s;
        for(auto i: nums1){
            s.insert(i);
        }
        vector<int> ans;
        for(auto i: nums2){
            if(s.count(i)){
                ans.push_back(i);
                s.erase(i);
            } 
        }
        return ans;
    }
};