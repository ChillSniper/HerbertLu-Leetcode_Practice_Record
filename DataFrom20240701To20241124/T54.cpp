#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int l = 0, r = matrix[0].size() - 1, top = 0, bottom = matrix.size() - 1;
        vector<int> ans;
        while (l <= r && top <= bottom)
        {
            for(int i = l;i <= r;i ++) ans.push_back(matrix[top][i]);
            top ++;
            for(int i = top;i <= bottom;i ++) ans.push_back(matrix[i][r]);
            r --;
            if(top <= bottom){
                for(int i = r;i >= l;i --) ans.push_back(matrix[bottom][i]);
                bottom --;
            }
            if(l <= r){
                for(int i = bottom;i >= top;i --) ans.push_back(matrix[i][l]);
                l ++;
            }
        }
        return ans;
    }
};

int main(){
    return 0;
}