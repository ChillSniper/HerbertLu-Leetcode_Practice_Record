#include <iostream>
#include <cstdio>
#include <cstring>
#include <unordered_map>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
#define Test

class RangeFreqQuery {
public:
    RangeFreqQuery(vector<int>& arr) {
        int sz = arr.size();
        for(int i = 0;i < sz;i ++)
            ump[arr[i]].push_back(i);        
    }
    
    int query(int left, int right, int value) {
        if(!ump.count(value)) return 0;
        
        // ��ʼ������ѯ��������ʱ��ԭ������Ϊʱ�临�Ӷ�ΪO(n)
        // ��vector<int>�д�����±�����˳��ģ����ǿ���������һ�㡣
        // �ɴˣ�����ʹ�ö��ֲ��ң���ʱ�临�ӶȽ���O(log n)
        int l = lower_bound(ump[value].begin(), ump[value].end(), left) - ump[value].begin();
        int r = upper_bound(ump[value].begin(), ump[value].end(), right) - ump[value].begin();
        return r - l;
    }
private:
    unordered_map<int, vector<int>> ump;
};

    /**
     * Your RangeFreqQuery object will be instantiated and called as such:
     * RangeFreqQuery* obj = new RangeFreqQuery(arr);
     * int param_1 = obj->query(left,right,value);
     */

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif

    return 0;
}