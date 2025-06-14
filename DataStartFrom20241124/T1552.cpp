#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
#define Test

class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        int sz = position.size();
        sort(position.begin(), position.end());
        int L = 1, R = position[sz - 1] - position[0];
        while (L < R)
        {
            int mid = L + (R - L) / 2;
            if(Enable(position, m, mid)) L = mid;
            else R = mid - 1;
        }
        return L;
    }
private:
    bool Enable(vector<int>& arr, int m, int x){
        int sz = arr.size();
        int cnt = 1, i = 0, st = 0;
        while (i < sz && st <= i)
        {
            if(arr[i] - arr[st] >= x){
                cnt ++;
                st = i;
            } else{
                i ++;
            }
        }
        return cnt >= m;
    }
};

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    vector<int> arr = {5,4,3,2,1,1000000000};
    int m = 2;
    Solution s;
    s.maxDistance(arr, m);
    return 0;
}