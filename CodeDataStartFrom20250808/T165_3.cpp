#include <bits/stdc++.h>
using namespace std;
#define Test

typedef pair<int, int> pr;
class Solution {
public:
    vector<vector<int>> generateSchedule(int n) {
        vector<vector<int>> ans(n * (n - 1), vector<int>(2, 0)), HasMatch(n, vector<int>(n, 0)); 
        priority_queue<pr, vector<pr>, greater<pr>> pq;
        deque<int> unvis;
        int st_idx = 0;
        for (int i = 0;i < n;i ++) {
            unvis.push_back(i);
        }             
        while (st_idx < n * (n - 1))
        {
            
        }
        
    }
};

int main() {

    return 0;
}