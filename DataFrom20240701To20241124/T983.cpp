#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
//#define Way1
#define Way2


#ifdef Way2
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        this->costs = costs;
        this->days = days;
        DayToEnd.assign(days.size(), 0);
        dp(0);
    }
    int dp(int i){
        if(i >= days.size()) return 0;
        if(DayToEnd[i]) return DayToEnd[i];
        DayToEnd[i] = INT_MAX;
        for(int k = 0;k < 3;k ++){
            int j = i;
            while (j < days.size() && days[j] < days[i] + Duration[k])
            {
                j ++;
            }
            DayToEnd[i] = min(DayToEnd[i], dp(j) + costs[k]);
        }
        return DayToEnd[i];
    }
private:
    vector<int> days, costs;
    vector<int> DayToEnd;
    int Duration[3] = {1, 7, 30};
};
#endif
#ifdef Way1
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // 遍历days[], sum = 
        // dynamic planning? at current condition, 
        // 注意要从后往前遍历
        for(auto d:days) DaysRecord[d] = 1;
        return Dp(costs, 1);
    }
    int Dp(vector<int>& costs, int i){
        if(i > 365) return 0;
        //  这边有一个问题，就是DayToEnd[]数组如果不记录，每次都算一遍的话会不会有不同的结果？
        if(DayToEnd[i] > 0) return DayToEnd[i];
        if(DaysRecord[i]){
            DayToEnd[i] =  min(min(Dp(costs, i + 1) + costs[0] , Dp(costs, i + 7) + costs[1]), Dp(costs, i + 30) + costs[2]);
        } else {
            DayToEnd[i] = Dp(costs, i + 1);
        }
        return DayToEnd[i];
    }
private:
    int DaysRecord[500] = {0};
    int DayToEnd[500] = {0};
};
#endif

int main(){
    freopen("file.in", "r", stdin);
    freopen("file.out", "w", stdout);

    return 0;
}