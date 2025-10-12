#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 1e1 + 10;
#define Test
void MergeSort(vector<int>& arr, int l, int r);
void Merge(vector<int>& arr, int l, int mid, int r);
void InsertionSort(vector<int>& arr);
void BubbleSort(vector<int>& arr);
void SelectionSort(vector<int>& arr);
void QuickSort(vector<int>& arr, int m, int n);
bool Check(vector<int>& arr1, vector<int>& arr2);
void ShellSort(vector<int>& arr);
int Partition(vector<int>& arr, int m, int n);
void ReArrange(vector<int>& arr);
bool CheckArrange(vector<int>& arr);
int main(){
    freopen("file.in", "r", stdin);
    freopen("file.out", "w", stdout);
    std::srand(std::time(nullptr));
    vector<int> arrForAlg(N), arrForStand(N);
    for(int i = 0;i < N;i ++)
        arrForAlg[i] = arrForStand[i] = std::rand() % 1000;
    // InsertionSort(arrForAlg);
    // BubbleSort(arrForAlg);
    // SelectionSort(arrForAlg);
    // ShellSort(arrForAlg);
    // QuickSort(arrForAlg, 0, N - 1);
    MergeSort(arrForAlg, 0, arrForAlg.size() - 1);
    sort(arrForStand.begin(), arrForStand.end());
    if(Check(arrForAlg, arrForStand)) printf("True");
    else printf("false");
    return 0;
}
void MergeSort(vector<int>& arr, int l, int r){
    if(l >= r) return ;
    int mid = l + (r - l) / 2;
    MergeSort(arr, l, mid);
    MergeSort(arr, mid + 1, r);
    Merge(arr, l, mid, r);
}
void Merge(vector<int>& arr, int l, int mid, int r){
    vector<int> tmp;
    int i = l, j = mid + 1;
    for(;i <= mid && j <= r;){
        if(arr[i] < arr[j]){
            tmp.push_back(arr[i]);
            i ++;
        }
        else if(arr[j] <= arr[i]){
            tmp.push_back(arr[j]);
            j ++;
        }
    }
    while(i <= mid){
        tmp.push_back(arr[i]); i ++;
    }
    while (j <= r){
        tmp.push_back(arr[j]); j ++;
    }
    for(int idx = 1;idx <= r - l + 1;idx ++){
        arr[idx + l - 1] = tmp[idx - 1]; 
    }
}
void ReArrange(vector<int>& arr){
    int len = arr.size(), i = 0, j = i - 1;
    while (i <= j)
    {
        while(arr[i] <= 0) i ++;
        while (arr[j] >= 0) j --;
        if(i <= j){
            swap(arr[i], arr[j]);
            i ++; j --;
        }
    }
}
bool CheckArrange(vector<int>& arr){
    int i = 0, j = arr.size() - 1;
    while (i <= j)
    {
        if(arr[i] > arr[j]) return false;
        i ++; j --;
    }
    return true;
}
void QuickSort(vector<int>& arr, int m, int n){
    if(m < n){
        int mid = Partition(arr, m, n);
        QuickSort(arr, m, mid - 1);
        QuickSort(arr, mid + 1, n);
    }
}
int Partition(vector<int>& arr, int m, int n){
    int K = arr[m], L = m + 1, R = n;
    while (L <= R)
    {
        while (arr[L] <= K && L <= n){L ++;}
        while (arr[R] > K && R >= m){R --;}
        if(L < R) {swap(arr[L], arr[R]); L ++; R --;}
    }
    swap(arr[R], arr[m]);
    return R;
}
void InsertionSort(vector<int>& arr){
    for(int i = 1;i < N;i ++){
        int j = i - 1, tmp = arr[i];
        while (j >= 0 && arr[j] > tmp)
        {
            arr[j + 1] = arr[j];
            j --;   
        }
        arr[j + 1] = tmp;
    }
}
void BubbleSort(vector<int>& a){
    int n = a.size(), bound = n - 1;
    while (bound > 0)
    {
        int t = 0;
        for(int i = 0;i < bound;i ++){
            if(a[i] > a[i + 1]){
                swap(a[i], a[i + 1]);
                t = i;
            }
        }
        bound = t;
    }
}
void SelectionSort(vector<int>& arr){
    int n = arr.size();
    for(int i = n - 1;i >= 0;i --){
        int t = 0;
        for(int j = 0;j <= i;j ++)
            if(arr[j] > arr[t]){t = j;}
        swap(arr[i], arr[t]);
    }
}
bool Check(vector<int>& arr1, vector<int>& arr2){
    for(int i = 0;i < N;i ++)
        if(arr1[i] != arr2[i]) return false;
    return true;
}
void ShellSort(vector<int>& arr){
    for(int d = N / 2;d > 0;d /= 2){
        for(int i = 0;i < N;i ++){
            int j = i - d, tmp = arr[i];
            while (j >= 0 && arr[j] > tmp)
            {
                arr[j + d] = arr[j];
                j -= d;
            }
            arr[j + d] = tmp;
        }
    }
}