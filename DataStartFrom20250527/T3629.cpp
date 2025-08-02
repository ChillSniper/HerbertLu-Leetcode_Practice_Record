#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <deque>
#include <unordered_map>
using namespace std;
#define Test

const int Max = 1e6 + 1;


class Solution {
public:
    int minJumps(vector<int>& nums) {
        // 这题有些地方很混乱
        // 问题是：你得搞清楚bfs的时候要去哪些地方？
        // 不知道为什么，在处理这些算法题的时候，思路总是处于一种非常不清晰的状态；
        // 此题在bfs的时候，需要处理，若val为质数，对当前val的倍数的下标的查找
        // 之前一直有个地方被卡住了，我一直在想，怎么寻找当前 k * val 的下标位置
        // 但是！ 可以逆向思维查找对于 一个val，其质因子p，p能跳到val的位置，而val的位置是已知的！
        // 这样的话，就比较容易处理了！但是这个思路很绕，容易被绕晕。
    }
private:
    void init(){
        
    }
};

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif

    return 0;
}