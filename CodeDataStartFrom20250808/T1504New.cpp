#include <bits/stdc++.h>
using namespace std;

#define Test

class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        // 这个用单调栈的做法确实非常抽象
        int m = mat.size(), n = mat[0].size(), ans = 0;
        vector<int> h(n, 0);
        for (auto& row : mat) {
            for (int i = 0;i < n;i ++) {
                if(row[i]) 
                    ++ h[i];
                else 
                    h[i] = 0;
            }
            vector<int> f(n, 0), lf(n, -1);
            stack<int> st;
            for (int i = 0;i < n;i ++) {
                while (st.size() && h[st.top()] >= h[i])
                {
                    st.pop();
                }
                if(st.size())
                    lf[i] = st.top();
                else 
                    lf[i] = -1;    
            
                int cur = lf[i] == -1 ? 0 : f[lf[i]];
                cur += (i - lf[i]) * h[i];
                ans += cur;
                f[i] = cur;
                st.push(i);
            }
        }
        return ans;
    }
};

int main() {
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    return 0;
}