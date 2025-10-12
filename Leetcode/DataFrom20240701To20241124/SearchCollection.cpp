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
        // ע��˴� Father[fx]��Father[fy]���Ǹ��� Ҳ����˵����� Father[fx] > Father[fy] ��ôʵ������fy������
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