#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int m = -1, n = piles.size();
        for(int i = 0;i < n;i ++)
            m = max(m, piles[i]);
        int l = 1, r = m;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if(EnableEatAll(piles, h, mid)) r = mid - 1;
            else l = mid + 1;
        }
        return l;
    }
private:
    bool EnableEatAll(vector<int>& piles, int h, int s){
        int n = piles.size(), t = 0;
        for(int i = 0;i < n;i ++){
            t += ceil(piles[i] * 1.0 / s); 
            if(t > h) return false;
        }
        return t <= h;
    }
};

int main(){
    return 0;
}