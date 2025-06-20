#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
#define Test

class Solution {
public:
    int maxDistance(string s, int k) {
        // 由于是顺序执行，所以我们不妨使得让它往一个方向跑
        // how to solve this problem ? 
        int sz = s.size(), num[300] = {0}, ans = 0;
        // character = 'N', 'S', 'E', 'W'
        for(auto ch : s){
            num[ch] ++;
            int k_cur = k;
            // x1, x2, |x2 - x1| + 2 * m
            // m = min(x1, x2, k)
            int row = min(min(num['N'], num['S']), k_cur);
            k_cur -= row;
            int col = min(min(num['E'], num['W']), k_cur);
            int target = abs(num['N'] - num['S']) + 2 * row + abs(num['E'] - num['W']) + 2 * col;
            ans = max(ans, target);
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