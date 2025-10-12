#include <iostream>
#include <cstdio>
#include <cstring>
#include <unordered_map>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
#define Test

class RangeFreqQuery {
public:
    RangeFreqQuery(vector<int>& arr) {
        int sz = arr.size();
        for(int i = 0;i < sz;i ++)
            ump[arr[i]].push_back(i);        
    }
    
    int query(int left, int right, int value) {
        if(!ump.count(value)) return 0;
        
        // 初始遍历查询的做法超时的原因是因为时间复杂度为O(n)
        // 而vector<int>中存入的下标是有顺序的，我们可以利用这一点。
        // 由此，可以使用二分查找，将时间复杂度降至O(log n)
        int l = lower_bound(ump[value].begin(), ump[value].end(), left) - ump[value].begin();
        int r = upper_bound(ump[value].begin(), ump[value].end(), right) - ump[value].begin();
        return r - l;
    }
private:
    unordered_map<int, vector<int>> ump;
};

    /**
     * Your RangeFreqQuery object will be instantiated and called as such:
     * RangeFreqQuery* obj = new RangeFreqQuery(arr);
     * int param_1 = obj->query(left,right,value);
     */

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif

    return 0;
}