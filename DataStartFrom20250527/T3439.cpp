#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define Test
class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int> PreUseTime(n, 0);
        for(int i = 0;i < n;i ++){
            if(i == 0){
                PreUseTime[i] = endTime[i] - startTime[i];
                continue;
            }            
            PreUseTime[i] = PreUseTime[i - 1] + endTime[i] - startTime[i];
        }    
        int Init_Right_Bound = k == n ? eventTime : startTime[k];
        int Ans = Init_Right_Bound - PreUseTime[k - 1];
        for(int i = k;i < n;i ++){
            int LeftBound = endTime[i - k];
            int RightBoud = i + 1 < n ? startTime[i + 1] : eventTime;
            Ans = max(Ans, RightBoud - LeftBound - (PreUseTime[i] - PreUseTime[i - k]));
        }
        return Ans;
    }
};
int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    return 0;
}