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
void InsertionSort(vector<int>& arr);
void BubbleSort(vector<int>& arr);
void SelectionSort(vector<int>& arr);
bool Check(vector<int>& arr1, vector<int>& arr2);
void ShellSort(vector<int>& arr);
int main(){
    freopen("file.in", "r", stdin);
    freopen("file.out", "w", stdout);
    std::srand(std::time(nullptr));
    vector<int> arrForAlg(N), arrForStand(N);
    for(int i = 0;i < N;i ++)
        arrForAlg[i] = arrForStand[i] = std::rand() % 1000;
    //InsertionSort(arrForAlg);
    //BubbleSort(arrForAlg);
    //SelectionSort(arrForAlg);
    ShellSort(arrForAlg);
    sort(arrForStand.begin(), arrForStand.end());
    if(Check(arrForAlg, arrForStand)) printf("True");
    else printf("false");
    return 0;
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