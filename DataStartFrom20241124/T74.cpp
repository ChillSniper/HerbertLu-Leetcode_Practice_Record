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
        int n = matrix.size(), m = matrix[0].size();
        int l = 0, r = n - 1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if(matrix[mid][0] == target)
                return true;
            if(matrix[mid][0] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        // at the position of r
        int row = r;
        if(row < 0)
            return false;
        l = 0, r = m - 1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if(matrix[row][mid] == target)
                return true;
            if(matrix[row][mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return false;   
    }
};

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    vector<vector<int>> matrix = {{1}};
    int target = 0;
    Solution s;
    s.searchMatrix(matrix, target);
    return 0;
}