#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
#define Test

class Solution {
public:
    int reversePairs(vector<int>& record) {
        ans = 0;
        Mergesort(record, 0, record.size() - 1);
        return ans;
    }
private:
    void Mergesort(vector<int>& arr, int l, int r){
        if(l >= r) return ;
        int mid = l + (r - l) / 2;
        Mergesort(arr, l, mid);
        Mergesort(arr, mid + 1, r);
        Merge(arr, l, mid, r);
    }
    void Merge(vector<int>& arr, int l, int mid, int r){
        // printf("Test\n");
        int i = l, j = mid + 1;
        vector<int> tmp;
        for(;i <= mid && j <= r;){
            if(arr[i] <= arr[j]){tmp.push_back(arr[i]);i ++;}
            else{
                tmp.push_back(arr[j]);
                j ++;
                ans += mid - i + 1;
            }
        }
        while(i <= mid){tmp.push_back(arr[i]);i ++;}
        while(j <= r){tmp.push_back(arr[j]);j ++;}
        for(int idx = 1;idx <= r - l + 1;idx ++) 
            arr[idx + l - 1] = tmp[idx - 1];
    }
    int ans;
};

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    int n;
    scanf("%d", &n);
    vector<int> num(n, 0);
    for(int i = 0;i < n;i ++)
        scanf("%d", &num[i]);
    Solution s;
    int ans = s.reversePairs(num);
    cout << ans;
    return 0;
}