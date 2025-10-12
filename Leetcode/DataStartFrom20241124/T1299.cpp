#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define Test

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int sz = arr.size();
        vector<int> ans(sz, -1);
        ans[sz - 1] = -1;
        for(int i = sz - 2;i >= 0;i --){
            ans[i] = max(arr[i + 1], ans[i + 1]);
        }
        return ans;
    }
};

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif

    return 0;
}