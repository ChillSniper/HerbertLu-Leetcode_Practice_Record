#include <iostream>
#include <unordered_set>
#include <math.h>
using  namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> mp;
        int CurrentNum = n;
        while (CurrentNum != 1)
        {
            int NextNum = 0;
            while (CurrentNum > 0)
            {
                NextNum += pow(CurrentNum % 10, 2);
                CurrentNum /= 10;
            }
            if(mp.count(NextNum)) return false;
            else {
                mp.insert(NextNum);
                CurrentNum = NextNum;
            }
        }
        return true;
    }
};

int main(){
    freopen("file.in", "r", stdin);
    freopen("file.out", "w", stdout);
    int n;
    cin >> n;
    Solution s;
    if(s.isHappy(n)) printf("Yes.");
    else printf("No.");
    return 0;
}