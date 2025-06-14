#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Solution {
public:
    void reverseString(vector<char>& s) {
        int LeftPointer = 0;
        int RightPointer = (int)s.size() - 1;
        while (LeftPointer < RightPointer)
        {
            swap(s[LeftPointer], s[RightPointer]);
            LeftPointer ++;
            RightPointer --;
        }
    }
};