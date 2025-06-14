#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        unordered_set<int> st1, st2;
        int n = nums.size();
        for(int i = 0;i < n;i ++){
            int num = nums[i];
            if(st1.count(num) && !st2.count(num)) st2.insert(num);
            else if(st2.count(num) && !st1.count(num)) st1.insert(num);
            else if(st1.count(num) && st2.count(num)) return false;
            else{
                if(st1.size() == st2.size()){
                    st1.insert(num);
                }
                else if(st1.size() > st2.size()) st2.insert(num);
                else st1.insert(num);
            }
        }
        return true;
    }
};