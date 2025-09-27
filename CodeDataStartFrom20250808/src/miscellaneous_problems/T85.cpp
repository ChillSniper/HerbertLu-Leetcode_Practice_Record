#include <bits/stdc++.h>
using namespace std;

#define Test

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), ans = 0;
        vector<int> record(n, 0); 
        for (int i = 0;i < m;i ++) {
            for (int j = 0;j < n;j ++) {
                if(matrix[i][j] == '0') {
                    record[j] = 0;
                }
                else {
                    record[j] ++;
                }
            }
            stack<int> st;
            vector<int> lf(n, -1), ri(n, n);
            for (int j = 0;j < n;j ++) {
                while (st.size() && record[st.top()] >= record[j])
                {
                    ri[st.top()] = j;
                    st.pop();
                }
                if(st.empty())
                    lf[j] = -1;
                else
                    lf[j] = st.top();
                st.push(i);
            }
            for (int j = 0;j < n;j ++) {
                ans = max(ans, (ri[j] - lf[j] - 1) * record[j]);
            }
        }     
        return ans;
    }
};

int main() {

    return 0;
}