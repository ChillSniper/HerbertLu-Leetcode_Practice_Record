#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 50;

class Solution {
public:
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        if(firstPlayer + secondPlayer == n + 1){
            return {1, 1};
        }

        if(firstPlayer + secondPlayer > n + 1){
            int record_first = n + 1 - secondPlayer;
            int record_right = n + 1 - firstPlayer;
            firstPlayer = record_first;
            secondPlayer = record_right;
        }

        // 此题实在是过于复杂
        // 总算把这个坐标变换看懂了，有很多很多细节需要注意        
        for(int i = 0;i < N;i ++){
            for(int j = 0;j < N;j ++){
                dp[i][j] = {-1, -1};
            }
        }
        int MidBound = (n + 1) / 2;
        // 这部分还是最好画图，不然什么都看不出来
        int LeftNumLower = 0;
        int LeftNumUpper = firstPlayer - 1;
        int MidNumLower = secondPlayer <= MidBound ? 0 : secondPlayer - 1 - n / 2;
        int MidNumUpper = secondPlayer <= MidBound ? secondPlayer - firstPlayer - 1 : MidBound - firstPlayer - 1;
        if(MidNumUpper < MidNumLower){
            MidNumLower = MidNumUpper = 0;
        }
        int MaxAns = -1, MinAns = 0x3f3f3f3f;
        int new_n = (n + 1) / 2;
        for(int i = LeftNumLower;i <= LeftNumUpper;i ++){
            for(int j = MidNumLower;j <= MidNumUpper;j ++){
                int new_first = i + 1;
                int new_right = i + 1 + j + 1;
                if(new_first + new_right > n + 1){
                    int record_first = new_n + 1 - new_right;
                    int record_right = new_n + 1 - new_first;
                    new_first = record_first;
                    new_right = record_right;
                }
                if(dp[new_first][new_right].first != -1){
                    MinAns = min(MinAns, dp[new_first][new_right].first + 1);
                    MaxAns = max(MaxAns, dp[new_first][new_right].second + 1);
                }
                else{
                    pair<int, int> p = dfs(new_n, new_first, new_right);
                    MinAns = min(MinAns, p.first + 1);
                    MaxAns = max(MaxAns, p.second + 1);
                }
            }
        }
        return {MinAns, MaxAns};
    }
private:
    pair<int, int> dfs(int n, int firstPlayer, int secondPlayer){
        if(firstPlayer + secondPlayer == n + 1){
            return {1, 1};
        }
        int MidBound = (n + 1) / 2;
        // 这部分还是最好画图，不然什么都看不出来
        int LeftNumLower = 0;
        int LeftNumUpper = firstPlayer - 1;
        int MidNumLower = secondPlayer <= MidBound ? 0 : secondPlayer - 1 - n / 2;
        int MidNumUpper = secondPlayer <= MidBound ? secondPlayer - firstPlayer - 1 : MidBound - firstPlayer - 1;
        int MaxAns = -1, MinAns = 0x3f3f3f3f;
        int new_n = (n + 1) / 2;
        for(int i = LeftNumLower;i <= LeftNumUpper;i ++){
            for(int j = MidNumLower;j <= MidNumUpper;j ++){
                int new_first = i + 1;
                int new_right = i + 1 + j + 1;
                if(new_first + new_right > n + 1){
                    int record_first = new_n + 1 - new_right;
                    int record_right = new_n + 1 - new_first;
                    new_first = record_first;
                    new_right = record_right;
                }
                if(dp[new_first][new_right].first != -1){
                    MinAns = min(MinAns, dp[new_first][new_right].first + 1);
                    MaxAns = max(MaxAns, dp[new_first][new_right].second + 1);
                }
                else{
                    pair<int, int> p = dfs(new_n, new_first, new_right);
                    MinAns = min(MinAns, p.first + 1);
                    MaxAns = max(MaxAns, p.second + 1);
                }
            }
        }
        return {MinAns, MaxAns};
    }
    pair<int, int> dp[N][N];
};

#define Test

int main(){
    
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    Solution s;
    s.earliestAndLatest(3, 2, 3);
    return 0;
}