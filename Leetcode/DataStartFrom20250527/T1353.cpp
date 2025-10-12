#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define Test

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        // �����ʱ��������Щ��ϵ��һ��ʼ��Ϊ�Ǹ��򵥵�����+̰�ģ�����ʵ���Ϻ���˵�Ҳ����ϵ��
        int LastTime = 1;
        for(auto& item : events){
            LastTime = max(LastTime, item[1]);
        }
        vector<vector<int>> record(LastTime + 1);
        for(auto& item : events){
            record[item[0]].push_back(item[1]);
        }
        priority_queue<int, vector<int>, greater<int>> pq;
        int ans = 0, cur_time = 1;
        for(int i = 1;i <= LastTime;i ++){
            if(i > cur_time){
                cur_time = i;
            }
            while (!pq.empty() && pq.top() < cur_time)
            {  
                pq.pop();
            }
            for(auto& item : record[i]){
                if(item >= cur_time){
                    pq.push(item);
                }
            }
            if((int)pq.size()){
                pq.pop();
                ans ++;
                cur_time ++;
            }
        }
        return ans;
    }
};

int main(){
    
    return 0;
}