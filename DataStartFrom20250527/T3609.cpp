#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define Test

class Solution {
public:
    int minMoves(int sx, int sy, int tx, int ty) {
        // m = max(x, y);
        // (x + m, y) or (x, y + m)
        // the Init: x >= y
        // 这道题实际上是个大模拟，而且需要详细的分类讨论：
        // from destination to the Init;
        if(sx == tx && sy == ty){
            return 0;
        }
        if(tx < ty){
            swap(tx, ty);
            swap(sx, sy);
        }
        // Then we discuss the situation.
        // 1. (ori_x + ori_x, ori_y) = (x, y)
        // it means : ori_x >= ori_y && x % 2 == 0, ori_x = x / 2;
        // equal: x % 2 == 0 && x >= 2 * y
        // 
        // 2. (ori_x + ori_y, ori_y) = (x, y)
        // it means: ori_x <= ori_y, ori_x = x - y
        // equal: x <= 2 * y
        // 
        // 3. (ori_x, ori_y + ori_x) = (x, y)
        // it means: ori_x >= ori_y, ori_y = y - x; However, ori_y < 0, illegal !
        // equal: 2 * x >= y
        //
        // 4. (ori_x, ori_y + ori_y) = (x, y)
        // it means: ori_x <= ori_y && y % 2 == 0, ori_y = y / 2;
        // equal: 2 * x <= y && y % 2 == 0 // illegal
        int cnt = 0;
        for(;tx >= sx && ty >= sy;){

            if(tx == ty){
                if(sy > 0){
                    tx = 0;
                }
                else{
                    ty = 0;
                }
            }

            else if(tx % 2 == 0 && tx >= 2 * ty){
                cnt ++;
                tx /= 2;
            }
            else if(tx <= 2 * ty){
                tx = tx - ty;
                cnt ++;
            }
            // else if(2 * tx >= ty){
            //     ty = ty - tx;
            //     cnt ++;
            // }
            else{
                return -1;
            }
            if(tx < 0 || ty < 0){
                return -1;
            }
            if(tx == sx && ty == sy){
                return cnt;
            }
            if(tx < ty){
                swap(tx, ty);
                swap(sx, sy);
            }
        }
        return -1;
    }
};

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    return 0;
}