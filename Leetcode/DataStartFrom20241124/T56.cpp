#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define Test
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end(), cmp);
        int Lf = intervals[0][0], Ri = intervals[0][1], sz = intervals.size();
        for(int i = 1;i < sz;i ++){
            int a = intervals[i][0], b = intervals[i][1];
            if(a == Lf){
                Ri = b;
            }
            else if(a > Lf && a <= Ri){
                if(b <= Ri){
                    ;
                } else{
                    Ri = b;
                }
            }
            else {
                ans.push_back({Lf, Ri});
                Lf = a;
                Ri = b;
            }
        }
        ans.push_back({Lf, Ri});
        return ans;
    }
private:
    static bool cmp(vector<int> a, vector<int> b){
        if(a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    }
};
int main(){
    return 0;
}