#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

#define Test

class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while (tx >= sx && ty >= sy)
        {
            if(tx == sx && ty == sy)
                return true;
            
            if(tx > ty){
                int s = (tx - sx) / ty;
                s = s ? s : s + 1;
                tx -= ty * s;
            }
            else if(tx < ty){
                int s = (ty - sy) / tx;
                s = s ? s : s + 1;
                ty -= tx * s;
            }
            else{
                return false;
            }
        }
        return false;
    }
};

int main(){

    return 0;
}