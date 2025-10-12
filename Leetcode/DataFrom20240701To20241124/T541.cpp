#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        int start = 0;
        while (start < (int)s.length())
        {
            if(start + 2 * k <= (int)s.length()){
                reverse(s.begin() + start, s.begin() + start + 2 * k);
            } else if(start + 2 * k > (int)s.length() && start + k > s.length()){
                reverse(s.begin() + start, s.end());
            } else {
                reverse(s.begin() + start, s.begin() + start + k);
            }
            start += 2 * k;
        }
        return s;
    }
};