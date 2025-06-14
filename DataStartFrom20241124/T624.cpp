#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define Test
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int sz = arrays.size();
        int res = 0, MaxNum = arrays[0][0], MinNum = arrays[0][arrays[0].size() - 1];
        for(int i = 1;i < sz;i ++){
            int secs = arrays[i].size();
            res = max(res, MaxNum - arrays[i][0]);
            res = max(res, arrays[i][sz - 1] - MinNum);
            MaxNum = max(MaxNum, arrays[i][sz - 1]);
            MinNum = min(MinNum, arrays[i][0]);
        }
        return res;
    }
};
int main(){
    return 0;
}