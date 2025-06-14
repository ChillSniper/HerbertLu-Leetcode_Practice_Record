#include <iostream>
#include <cstdio>
using namespace std;
//#define TypeOriginal
#define TypeFinal
const int N = 1e5 + 10;

#ifdef TypeOriginal
class Solution{
public:
    void MakeSet(int x){
        Father[x] = 0;
    }
    int FindFather(int x){
        if(Father[x] == 0) return x;
        Father[x] = FindFather(Father[x]);
        return Father[x];
    }
    void Union(int x, int y){
        Father[FindFather(y)] = FindFather(x);
    }
private:
    int Father[N] = {0};
};
#endif

#ifdef TypeFinal
class Solution{
public:
    void MakeSet(int x){
        Father[x] = 0;
    }
    int FindFather(int x){
        if(Father[x] <= 0) return x;
        Father[x] = FindFather(Father[x]);
        return Father[x];
    }
    void Union(int x, int y){
        int fx = FindFather(x), fy = FindFather(y);
        // 注意此处 Father[fx]和Father[fy]都是负数 也就是说，如果 Father[fx] > Father[fy] 那么实际上是fy的树高
        if(Father[fx] > Father[fy]){
            Father[fx] = fy;
        } else{
            if(Father[fx] == Father[fy]) Father[fx] --;
            Father[fy] = fx;
        }
    }
private:
    int Father[N] = {0};
};
#endif

int main(){
    freopen("file.in", "r", stdin);
    freopen("file.out", "w", stdout);
    
    return 0;
}