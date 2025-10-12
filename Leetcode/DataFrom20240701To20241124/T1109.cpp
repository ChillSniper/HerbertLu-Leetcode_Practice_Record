#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> Ans(n, 0);
        for(int i = 0;i < bookings.size();i ++){
            Ans[bookings[i][0] - 1] += bookings[i][2];
            if(bookings[i][1] <= n) Ans[bookings[i][1]] -= bookings[i][2]; 
        }
        for(int i = 1;i < n;i ++){
            Ans[i] += Ans[i - 1];
        }
        return Ans;
    }
};

int main(){
    freopen("file.in", "r", stdin);
    freopen("file.out", "w", stdout);

    return 0;
}