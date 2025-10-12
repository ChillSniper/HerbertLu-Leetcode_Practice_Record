#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

class Solution {
public:
    int findRepeatDocument(vector<int>& documents) {
        int sz = documents.size();
        for(int i = 0;i < sz;i ++){
            while (1)
            {
                int x = documents[i];
                if(x == i) break;
                int pos = x;
                if(documents[pos] == x) return x;
                swap(documents[pos], documents[i]);
            }
        }
        return -1;
    }
};