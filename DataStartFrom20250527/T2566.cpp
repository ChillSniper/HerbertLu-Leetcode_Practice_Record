#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#include <unordered_set>
using namespace std;
#define Test

class Solution {
public:
    int minMaxDifference(int num) {
        // 打个暴力得了，省的那些乱七八糟的
        unordered_set<int> st;
        int num_record = num;
        while (num)
        {
            int lst = num % 10;
            num /= 10;
            st.insert(lst);
        }
        vector<int> store;  
        for(auto item : st){
            for(int i = 0;i < 9;i ++){
                int val = change(item, i, num_record);
                store.push_back(val);
            }
        }
        return *max_element(store.begin(), store.end()) - *min_element(store.begin(), store.end());
    }
private:
    int change(int d1, int d2, int num){
        vector<int> tmp;
        while (num)
        {
            int t = num % 10;
            num /= 10;
            t = t == d1 ? d2 : t;
            tmp.push_back(t);
        }
        int result = 0, sz = tmp.size();
        for(int i = 0;i < sz;i ++){
            result += (tmp[i]) * (int)pow(10, i);
        }
        return result;
    }
};    

int main(){

    return 0;
}