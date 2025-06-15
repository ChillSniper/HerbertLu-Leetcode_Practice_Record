#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define Test

class Solution {
public:
    int maxDiff(int num) {
        // change min:
        // if First num = 1 to next:
        
        // 有第二位的话，进行分类讨论，要么改成1，要么改成0
        // 然后把第一位那个数字改成9
        int MaxNum = DecideMax(num);
        int MinNum = DecideMin(num);
        cout << "MaxNum = " << MaxNum << endl;
        cout << "MinNum = " << MinNum << endl;
        return MaxNum - MinNum;
        return DecideMax(num) - DecideMin(num);

    }
private:
    void DivideTheNum(int num, vector<int>& store){
        while (num)
        {
            int t = num % 10;
            store.push_back(t);
            num /= 10;
        }
        reverse(store.begin(), store.end());
    }
    int DecideMax(int num){
        vector<int> store;
        DivideTheNum(num, store);
        int len = store.size();
        for(int i = 0;i < len;i ++){
            if(store[i] != 9){
                return ChangeNum(num, store[i], 9);
            }
        }
        return num;
    }
    int DecideMin(int num){
        // 
        vector<int> store;
        DivideTheNum(num, store);
        int len = store.size();
        if(store[0] != 1){
            return ChangeNum(num, store[0], 1);
        }
        for(int i = 1;i < len;i ++){
            if(store[i] != 1 && store[i] != 0){
                return ChangeNum(num, store[i], 0);
            }
        }
        return num;
    }
    int ChangeNum(int originalNum, int pre, int target){
        int p = 1, Num = 0;
        while (originalNum)
        {
            int t = originalNum % 10;
            originalNum /= 10;
            t = t == pre ? target : t;
            Num += (p * t);
            p *= 10;
        }
        return Num;        
    }
};

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    Solution s;
    s.maxDiff(1101057);
    return 0;
}