#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <unordered_set>
using namespace std;
#define Test

typedef long long ll;
const int N = 1e9 + 10;
class Solution {
public:
    bool reorderedPowerOf2(int n) {
        ll init_num = 1;
        for (;init_num <= N;init_num <<= 1) {
            string s = to_string(init_num);
            sort(s.begin(), s.end());
            st.insert(s);            
        }
        string target = to_string(n);
        sort(target.begin(), target.end());
        return st.count(target);
    }
private:
    unordered_set<int> st;

};

int main() {

    return 0;
}