#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define Test

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int Ans = 0;
        while (l < r)
        {
            Ans = max(Ans, min(height[l], height[r]) * (r - l));
            if(height[l] >= height[r]) r --;
            else l ++;
        }
        return Ans;
    }
};

int main(){

    return 0;
}