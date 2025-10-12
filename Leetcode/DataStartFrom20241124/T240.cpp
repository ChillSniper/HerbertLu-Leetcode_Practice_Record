#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define Test

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size(), st_i = 0, st_j = n - 1;
        while (st_i >= 0 && st_i < m && st_j >= 0 && st_j < n)
        {
            int x = matrix[st_i][st_j];
            if(x == target) return true;
            else if(x > target){
                st_i --;
            } else{
                st_j ++;
            }
        }
        return false;
    }
};

int main(){

    return 0;
}