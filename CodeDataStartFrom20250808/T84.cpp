#include <bits/stdc++.h>
using namespace std;

#define Test

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> lf(n, -1), ri(n, n);
        stack<int> st;
        // how to design this single stack ?
        // increase.

        for (int i = 0;i < n;i ++) {
            while (st.size() && heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            if(st.empty())
                lf[i] = -1;
            else 
                lf[i] = st.top();
            st.push(i);
        }
        while(st.size()){
            st.pop();
        }
        for (int i = n - 1;i >= 0;i --) {
            while (st.size() && heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            if(st.empty())
                ri[i] = n;
            else
                ri[i] = st.top();
        }
        int ans = 0;
        for (int i = 0;i < n;i ++) {
            int curval = (ri[i] - 1 - lf[i]) * heights[i];
            ans = max(ans, curval);
        }
        return ans;
    }
};

int main() {

    return 0;
}