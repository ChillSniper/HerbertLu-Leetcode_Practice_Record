#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
using namespace std;
#define Test

struct Information{
    int LeftIndex;
    int RightIndex;
    int Len;
    bool operator < (const Information& other) const {
        return this->Len < other.Len;
    }
};

class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        // 一个稍微有点麻烦的办法，维护一个优先队列。
        priority_queue<Information> dq, tmp_dq;
        int n = startTime.size();
        int MaxBlank = 0, ans = 0;
        for(int i = 0;i < n;i ++){
            int left_bound = i > 0 ? endTime[i - 1] : 0;
            int right_boud = i < n - 1 ? startTime[i + 1] : eventTime;
            MaxBlank = max(MaxBlank, startTime[i] - left_bound);
            MaxBlank = max(MaxBlank, right_boud - endTime[i]);    
            tmp_dq.push({i - 1, i, startTime[i] - left_bound});
        }
        tmp_dq.push({n - 1, n, eventTime - endTime[n - 1]});
        ans = MaxBlank;
        int cnt = 0;
        while (cnt < 3 && (int)tmp_dq.size() > 0)
        {
            dq.push(tmp_dq.top());
            tmp_dq.pop();
            ++ cnt;
        }
        for(int i = 0;i < n;i ++){
            int left_bound = i > 0 ? endTime[i - 1] : 0;
            int right_bound = i < n - 1 ? startTime[i + 1] : eventTime;
            int cur_use = endTime[i] - startTime[i];
            bool flag = false;
            if(cur_use <= MaxBlank){
                stack<Information> st;
                while (dq.size())
                {
                    Information cur = dq.top(); dq.pop();
                    st.push(cur);
                    if(cur.LeftIndex != i && cur.RightIndex != i && cur.Len >= cur_use){
                        flag = true;
                        break;
                    }
                }
                while (st.size())
                {
                    dq.push(st.top());
                    st.pop();
                }
            }
            int target = flag ? right_bound - left_bound : right_bound - left_bound - cur_use;
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