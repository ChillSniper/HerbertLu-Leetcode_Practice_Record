#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define Test

class FindSumPairs {
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        for(auto item : nums1){
            ++ setA[item];
        }
        for(auto item : nums2){
            ++ setB[item];
        }
        storeB = nums2;
    }
    
    void add(int index, int val) {
        int orival = storeB[index];
        if(--setB[orival] == 0){
            setB.erase(orival);
        }
        storeB[index] = orival + val;
        ++ setB[orival + val];
    }
    
    int count(int tot) {
        int cnt = 0;
        for(auto item : setA){
            if(setB.count(tot - item.first)){
                cnt += item.second * setB[tot - item.first];
            }
        }
        return cnt;
    }
private:
    unordered_map<int, int> setA;
    unordered_map<int, int> setB;
    vector<int> storeB;
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */

int main(){
    return 0;
}