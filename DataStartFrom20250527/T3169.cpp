#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define Test

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        // 这个题实际上是记录每个连续的区间
        sort(meetings.begin(), meetings.end(), [](auto& a, auto& b){
            return a[0] < b[0];
        });
        int n = meetings.size(), use_time = 0, Left_Bound = meetings[0][0], Right_Bound = -1;
        for(auto& v : meetings){
            int l = v[0], r = v[1];
            if(l == Left_Bound){
                Right_Bound = max(r, Right_Bound);
            }
            else if(l > Left_Bound){
                if(l > Right_Bound){
                    use_time += Right_Bound - Left_Bound + 1;
                    Left_Bound = l;
                    Right_Bound = r;
                }
                else{
                    Right_Bound = max(r, Right_Bound);
                }
            }
        }
        use_time += Right_Bound - Left_Bound + 1;
        return days - use_time;
    }
};

int main(){
    return 0;
}