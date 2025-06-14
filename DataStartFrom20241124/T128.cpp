#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;
#define Test

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mp;
        int sz = nums.size();
        for(int i = 0;i < sz;i ++){
            mp[nums[i]] = 0;
        }
        for(auto i : mp){
            if(!i.second){
                FindLen(mp, i.first);
            }
        }
        return MaxLen;
    }
private:
    void FindLen(unordered_map<int, int>& mp, int x){
        int Len = 1;
        int j = x - 1;
        while (mp.count(j))
        {
            Len ++;
            j --;
        }
        j = x + 1;
        while (mp.count(j))
        {
            Len ++;
            j ++;
        }
        MaxLen = max(MaxLen, Len);
    }
    int MaxLen = 0;
};

int main(){

    return 0;
}