#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
#define Test
class Allocator {
    public:
        Allocator(int n) {
            for(int i = 0;i < n;i ++) a.push_back(0);
        }
        
        int allocate(int size, int mID) {
            int sl = 0, fs = 0, sz = a.size();
            for(;sl <= fs && fs < sz;){
                if(a[fs] == 0){
                    while (fs < sz && a[fs] == 0 && fs - sl + 1 < size)
                    {
                        ++ fs;
                    }
                    if(fs - sl + 1 == size && fs < sz && a[fs] == 0){
                        for(int j = sl;j <= fs;j ++) a[j] = mID;
                        return sl;
                        break;
                    } else{
                        sl = fs;
                    }
                } else{
                    fs ++;
                    sl ++;
                }
            }
            return -1;
        }
        
        int freeMemory(int mID) {
            int sz = a.size(), cnt = 0;
            for(int i = 0;i < sz;i ++){
                if(a[i] == mID) {
                    a[i] = 0;
                    cnt ++;
                }
            }
            return cnt;
        }
    private:
        vector<int> a;
    };

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->freeMemory(mID);
 */
int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    return 0;
}