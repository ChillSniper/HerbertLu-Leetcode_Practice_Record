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
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int sz = temperatures.size();
        vector<int> ans(sz, 0);
        stack<int> st;
        for(int i = 0;i < sz;i ++){
            while (st.size() && temperatures[st.top()] < temperatures[i])
            {
                int x = st.top(); st.pop();
                ans[x] = i - x;
            }
            st.push(i);
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