#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
#define Test

class Solution {
    public:
        int largestRectangleArea(vector<int>& heights) {
            int sz = heights.size();
                // 这题显然提示要用单调栈来做，但是怎么入手做呢？
                // 对于每个元素，要寻找其左右两侧比他小的元素，这就是边界 （开区间）
                // 
                vector<int> L(sz, -2), R(sz, -2);
                stack<int> st;
                for(int i = 0;i < sz;i ++){
                    while (st.size() && heights[st.top()] >= heights[i])
                    {
                        st.pop();
                    }
                    L[i] = st.size() != 0 ? st.top() : -1;
                    st.push(i);
                }
                while (st.size())
                {
                    st.pop();
                }
                
                for(int i = sz - 1;i >= 0;i --){
                    while (st.size() && heights[st.top()] >= heights[i])
                    {
                        st.pop();
                    }   
                    R[i] = st.size() != 0 ? st.top() : sz;
                    st.push(i);
                }
                int ans = 0;
                for(int i = 0;i < sz;i ++){
                    int left = (L[i] == -2) ? i : L[i] + 1;
                    int right = (R[i] == -2) ? i : R[i] - 1;
                    int tmp = (right - left + 1) * heights[i];
                    ans = max(ans, tmp);
                }
                return ans;
        }
    };

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    vector<int> H = {1, 1};
    Solution s;
    s.largestRectangleArea(H);
    return 0;
}