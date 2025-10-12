#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define Test

const int N = 4e3 + 10;
class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        vector<int> f(N, 0);
        // 这道题的问题在于先要排序这个数组，否则选择的次序会发生变换
        // 我们排序的目的在于，由于如果选择了这个元素x，那么x > a_{i - 1}
        sort(rewardValues.begin(), rewardValues.end());
        int sz = rewardValues.size();
        int s = 0, MaxNum = 0;
        f[0] = 1;
        for(int i = 1;i <= sz;i ++){
            int x = rewardValues[i - 1];
            s += x;
            for(int j = min(s, 2 * x - 1);j >= x;j --){
                f[j] = f[j] || f[j - x];
                if(f[j])
                    MaxNum = max(MaxNum, j);
            }
        }    
        return MaxNum;
    }
private:
    
};

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    vector<int> arr = {1, 1, 3, 3};
    Solution s;
    cout << s.maxTotalReward(arr);
    return 0;
}