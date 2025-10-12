#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
using  namespace std;

#define Test
// #define WayOfDp
#define WayOfSingleStack
// #define WayOfTwoPointer

/*
    ����ʵ�����ж��ֽⷨ
    ��Ѱ��ÿ��������Ҹ������ֵ������̬�滮

    ��Ѱ�ҵ�ǰ������ˮ��-> ����ջ

    ���Ż���̬�滮�ռ临�Ӷ�����˫ָ��ⷨ
*/

#ifdef WayOfSingleStack
class Solution {
public:
    int trap(vector<int>& height) {
        int sum = 0, sz = height.size(), lh = 0;
        stack<int> st;
        for(int i = 0;i < sz;i ++){
            while (!st.empty() && height[i] >= height[st.top()])
            {
                int x = (i - st.top() - 1) * (height[st.top()] - lh);
                sum += x;
                lh = height[st.top()];
                st.pop();
            }
            if(!st.empty())
                sum += (i - st.top() - 1) *(height[i] - lh);
            st.push(i);
            // lh = 0;
        }
        return sum;
    }
}; 
#endif

#ifdef WayOfTwoPointer
class Solution {
public:
    int trap(vector<int>& height) {
        int sum = 0, sz = height.size();
        int Left = 0, Right = sz - 1, LeftMax = 0, RightMax = 0;
        while (Left <= Right)
        {
            LeftMax = max(LeftMax, height[Left]);
            RightMax = max(RightMax, height[Right]);
            if(height[Left] > height[Right]){
                sum += RightMax - height[Right];
                Right --;
            } else{
                sum += LeftMax - height[Left];
                Left ++;
            }
        }
        return sum;
    }
};
#endif

#ifdef WayOfDp
class Solution {
public:
    int trap(vector<int>& height) {
        // �ҵ������ˣ������Ҷ���ÿ��height[i]��Ѱ����������ֵ���Ҳ����ֵ
        int sz = height.size();
        vector<int> LeftMax(sz, 0), RightMax(sz, 0);
        for(int i = 1;i < sz;i ++){
            LeftMax[i] = max(LeftMax[i - 1], height[i - 1]);
        }
        for(int i = sz - 2;i >= 0;i --){
            RightMax[i] = max(RightMax[i + 1], height[i + 1]);
        }
        int sum = 0;
        // for(int i = 0;i < sz;i ++){
        //     printf("%d ", LeftMax[i]);
        // }
        // cout << endl;
        for(int i = 0;i < sz;i ++){
            int x = min(LeftMax[i], RightMax[i]) - height[i];
            x = (x >= 0) ? x : 0;
            sum += x;
        }
        return sum;
    }
};
#endif

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    vector<int> h = {4,2,0,3,2,5};
    Solution s;
    cout << s.trap(h);
    return 0;
}