#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define Test

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int sz = arr.size(), CurNum = -1, cnt = 0;
        for(int i = 0;i < sz;i ++){
            if(arr[i] == CurNum){
                cnt ++;
                if(cnt > sz / 4) return arr[i];
            } else{
                cnt = 1;
                CurNum = arr[i];
            }
        }
        return -1;
    }
};

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    return 0;
}