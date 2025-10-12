#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define Test
int InterpolartionSearch(int arr[], int n, int K);
int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif

    return 0;
}
int InterpolartionSearch(int arr[], int n, int K){
    int l = 1, r = n, mid;
    while (arr[l] <= K && arr[r] >= K && l <= r)
    {
        // the essence
        // (mid - l) / (r - l) = (k - arr[l]) / (arr[r] - arr[l])
        mid = (K - arr[l]) * (r - l) / (arr[r] - arr[l]);
        if(arr[mid] == K) return mid;
        else if(arr[mid] > K) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}