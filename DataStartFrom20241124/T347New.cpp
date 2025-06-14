#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
#define Test

const int N = 1e5 + 10;
int heap_size;
typedef unordered_map<int, int>::iterator it;
it a[N];
class Solution {
    public:
        vector<int> topKFrequent(vector<int>& nums, int k) {
            // memset(a, 0, sizeof a);
            heap_size = 0;
            vector<int> ans;
            int sz = nums.size();
            for(int i = 0;i < sz;i ++){
                ump[nums[i]] ++;
            }
            int cnt = 0;
            for(it i = ump.begin();i != ump.end();i = next(i), cnt ++){
                if(cnt < k){
                    a[++ heap_size] = i;
                }
                else{
                    if(i->second > a[heap_size]->second){
                        swap(i, a[heap_size]);
                        ShiftUp(heap_size);
                    }
                }
            }
            cout << cnt << endl;
            for(int i = 1;i <= k;i ++){
                ans.push_back(a[i]->first);
            }
            return ans;
        }
    private:
        unordered_map<int, int> ump;
        void ShiftUp(int i){
            while (i / 2 >= 1 && a[i / 2]->second < a[i]->second)
            {
                swap(a[i / 2], a[i]);
                i /= 2;
            }
        }
        void ShiftDown(int i){
            int t = i;
            if(i * 2 <= heap_size && a[i * 2]->second > a[t]->second)
                t = i * 2;
            if(i * 2 + 1 <= heap_size && a[i * 2 + 1]->second > a[t]->second)
                t = i * 2 + 1;
            if(t == i)
                return ;
            swap(a[t], a[i]);
            ShiftDown(t);
        }
        void Buildheap(){
            for(int i = heap_size / 2;i >= 1;i --){
                ShiftDown(i);
            }
        }
};

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    Solution s;
    vector<int> arr = {1,1,1,2,2,3};
    s.topKFrequent(arr, 2);
    return 0;
}