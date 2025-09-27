#include <bits/stdc++.h>
using namespace std;

#define Test

typedef pair<double, int> pr;
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        // 这个有点像数学问题
        int n = classes.size();
        priority_queue<pr> t;
        for (int i = 0;i < n;i ++) {
            t.push({(1 + 1.0 * classes[i][0] ) / (classes[i][1] + 1) - 1.0 * classes[i][0] / classes[i][1], i});
        }
        for (int i = 0;i < extraStudents;i ++) {
            auto f = t.top();
            t.pop();
            int index = f.second;
            classes[index][0] ++;
            classes[index][1] ++;
            t.push({(1 + 1.0 * classes[i][0] ) / (classes[i][1] + 1) - 1.0 * classes[i][0] / classes[i][1], i});
        }
        double all = 0;
        for (int i = 0;i < n;i ++) {
            all += 1.0 * classes[i][0] / classes[i][1];
        }
        return all / n;
    }
};

int main() {
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    return 0;
}