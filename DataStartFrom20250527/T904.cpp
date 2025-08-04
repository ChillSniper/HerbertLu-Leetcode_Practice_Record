#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

#define Test

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l = 0, r = 0;
        // unordered_set<int> record;
        unordered_map<int, int> record;
        int ans = 0, cur_sum = 0, n = fruits.size();
        for (;l <= r && r < n;++ r) {
            int f_r = fruits[r];
            int f_l = fruits[l];
            if(!record.count(f_r)) {
                if(record.size() < 2) {
                    ;
                }
                else {
                    while (record.size() == 2 && l <= r)
                    {
                        record[fruits[l]] --;
                        cur_sum -= 1;
                        if(record[fruits[l]] == 0){
                            record.erase(fruits[l]);
                        }
                        l ++;
                    }
                }
                record[f_r] = 1;
                cur_sum += 1;
                ans = max(ans, cur_sum);
            }
            else {
                ++ record[f_r];
                cur_sum += 1;
                ans = max(ans, cur_sum);
            }
        }
        return ans;
    }
};

int main(){

    return 0;
}