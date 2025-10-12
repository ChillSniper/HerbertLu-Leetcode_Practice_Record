#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <vector>
using namespace std;

class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int sz = arr.size(), cnt = 0;
        for(int i = 0;i < sz;i ++){
            for(int j = i + 1;j < sz;j ++){
                for(int k = j + 1;k < sz;k ++){
                    if(abs(arr[i] - arr[j]) <= a && abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c){
                        cnt ++;
                    }
                }
            }
        }
        return cnt;
    }
};

int main(){
    
    return 0;
}