#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
#define Test
// Quick Chosing Algorithm

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return FindNum(nums, 0, nums.size() - 1, k);
    }
private:
    int FindNum(vector<int>& num, int L, int R, int k){
        int pos = Partition(num, L, R);
        if(R - pos + 1 == k) return num[pos];
        if(R - pos + 1 > k) return FindNum(num, pos, R, k);
        return FindNum(num, L, pos - 1, k + pos - R - 1);
    }
    int Partition(vector<int>& num, int L, int R){
        if(L > R) return -1;
        int K = num[L], pl = L + 1, pr = R;
        while (pl <= pr)
        {
            while(pl <= R && num[pl] <= K){ pl ++;}
            while(pr > L && num[pr] > K){ pr --;}
            if(pl < pr){
                swap(num[pl], num[pr]);
            }
        }
        swap(num[pr], num[L]);
        return pr;
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
    int ans = s.findKthLargest(num, k);
    printf("%d", ans);
    // printf("%d", num[50009]);
    // for(int i = 1;i <= 30000;i ++) printf("1 ");
    return 0;
}