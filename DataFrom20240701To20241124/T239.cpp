#include <iostream>
#include <vector>
#include <deque>
#include <queue>
using namespace std;
//#define Way1
#define Way2

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        #ifdef Way1
        vector<int> ans;
        for(int i = 0;i < k && i < nums.size();i ++) PushElement(nums[i]);
        ans.push_back(dq.front());
        for(int i = k;i < nums.size();i ++){
            PopElement(nums[i - k]);
            PushElement(nums[i]);
            ans.push_back(dq.front());
        }
        return ans;
        #endif
        #ifdef Way2
        priority_queue<pair<int, int>> q;
        vector<int> ans;
        for(int i = 0;i < k && i < nums.size();i ++){
            q.emplace(nums[i], i);
        }
        ans.push_back(q.top().first);
        for(int i = k;i < nums.size();i ++){
            q.emplace(nums[i], i);
            while (q.top().second <= i - k)
            {
                q.pop();
            }
            ans.push_back(q.top().first);
        }
        return ans;
        #endif
    }
    void PushElement(int x){
        while(!dq.empty() && x > dq.back()){
            dq.pop_back();
        }
        dq.push_back(x);
    }
    void PopElement(int x){
        if(x == dq.front()) dq.pop_front();
    }
private:
    deque<int> dq;
};

int main(){
    freopen("file.in", "r", stdin);
    freopen("file.out", "w", stdout);
    int N, k; 
    cin >> N >> k;
    vector<int> nums(N);
    for(int i = 0;i < N;i ++) scanf("%d", &nums[i]);
    Solution s;
    vector<int> ans = s.maxSlidingWindow(nums, k);
    for(int i = 0;i < ans.size();i ++) printf("%d ", ans[i]);
    return 0;
}