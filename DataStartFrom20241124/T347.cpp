#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <unordered_map>
using namespace std;
#define Test

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        unordered_map<int, int> flag;
        for(int i = 0;i < n;i ++) mp[nums[i]] ++;
        int pos;
        for(int i = 0;i < n;i ++){
            if(!flag.count(nums[i])){
                ++ heap_size;
                a[heap_size].num = nums[i];
                a[heap_size].cnt = mp[nums[i]];
                flag[nums[i]] = 1;
                if(heap_size == k){
                    pos = i;
                    break;
                }
            }
        }
        for(int i = heap_size;i >= 1;i --){
            ShiftUp(i);
            ShiftDown(i);
        }
        for(int i = pos + 1;i < n;i ++){
            if(mp[nums[i]] > a[1].cnt && !flag.count(nums[i])){
                a[1].cnt = mp[nums[i]];
                a[1].num = nums[i];
                flag[nums[i]] = 1;
                ShiftDown(1);
            }
        }
        vector<int> ans;
        for(int i = 1;i <= k;i ++){
            ans.push_back(a[i].num);
        }
        return ans;
    }
private:
    static const int N = 1e5 + 10;
    struct Info
    {
        int num;
        int cnt;
    };
    Info a[N];
    int heap_size;
    void ShiftDown(int i){
        while (i <= heap_size)
        {
            int idx = i;
            if(i * 2 <= heap_size && a[i * 2].cnt < a[idx].cnt) idx = i * 2;
            if(i * 2 + 1 <= heap_size && a[i * 2 + 1].cnt < a[idx].cnt) idx = i * 2 + 1;
            if(idx == i) return;
            swap(a[idx], a[i]);
            i = idx;
        }
    }
    void ShiftUp(int i){
        while (i / 2 >= 1 && a[i / 2].cnt > a[i].cnt)
        {
            swap(a[i / 2], a[i]);
            i /= 2;
        }
    }
};

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    int n, k;
    scanf("%d%d", &n, &k);
    vector<int> num(n, 0);
    for(int i = 0;i < n;i ++)
        scanf("%d", &num[i]);
    Solution s;
    vector<int> ans = s.topKFrequent(num, k);
    return 0;
}