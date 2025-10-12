#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define Test

class Solution {
    public:
        vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
            vector<int> ans;
            sort(items.begin(), items.end(), cmp);
            // n * logn
            // binary search
            int sz = queries.size(), n = items.size();
            for(int i = 1;i < sz;i ++){
                items[i][1] = max(items[i][1], items[i - 1][1]);
            }
            for(int i = 0;i < sz;i ++){
                int x = queries[i];
                int l = 0, r = n - 1;
                while (l <= r)
                {
                    int mid = l + (r - l) / 2;
                    if(items[mid][0] <= x){
                        l = mid + 1;
                    }
                    else
                    {
                        r = mid - 1;
                    }
                }
                if(!(r >= 0 && r < n) || items[r][0] > x)
                    ans.push_back(0);
                else
                    ans.push_back(items[r][1]);
            }
            return ans;
        }
    private:
        static bool cmp(vector<int> a, vector<int> b){
            if(a[0] == b[0])
                return a[1] < b[1];
            return a[0] < b[0];
        }
    };

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif

    return 0;
}