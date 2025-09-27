#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        // 首先有几个问题
        // 1. array index和 array.first 是不对应的，这个该如何处理 ？
        // 2. 如何想到那个贪心的办法 ？
        // 3. 出于贪心的算法，该怎么执行后续的解决步骤呢 ？
        int Left, n = fruits.size();
        for (Left = 0;Left < n;Left ++) {
            if(startPos - fruits[Left][0] <= k) {
                break;
            }
        }
        int sum = 0, R;
        for (R = Left;R < n && fruits[R][0] <= startPos;++ R) {
            sum += fruits[R][1];
        }
        int START_INDEX = R - 1;
        int ans = sum;
        for (;R < n && fruits[R][0] - startPos <= k; ++ R) {
            sum += fruits[R][1];
            while(startPos - fruits[Left][0] + fruits[R][0] - fruits[Left][0] > k &&
                  fruits[R][0] - startPos + fruits[R][0] - fruits[Left][0] > k &&
                  Left <= START_INDEX)
            {   
                sum -= fruits[Left][1];
                ++ Left;
            }
            ans = max(ans, sum);
        }
        return ans;
    }
};

int main() {

    return 0;
}