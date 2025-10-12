#include <iostream>
#include <cstdio>
#include <deque>
using namespace std;
#define Test
const int MAX = 0x3f3f3f3f;
struct Edge{
    int cost;
    int VerAdj;
    Edge* link;
};
struct Vertex{
    int VerName;
    Edge* Adjacent;
};

void BfsForShortestPath(Vertex* head, int u, int n, int pre[], int distance[]);
int main(){

    return 0;
}
void BfsForShortestPath(Vertex* head, int u, int n, int pre[], int distance[]){
    deque<int> dq;
    // pay attention to the preparation
    for(int i = 1;i <= n;i ++){
        pre[i] = -1; distance[i] = MAX;
    }
    distance[u] = 0;
    dq.push_back(u);
    while (!dq.empty())
    {
        int k = dq.front(); dq.pop_front();
        for(Edge* p = head[k].Adjacent;p;p = p->link){
            if(distance[p->VerAdj] == MAX){
                pre[p->VerAdj] = k;
                distance[p->VerAdj] = distance[k] + 1;
                dq.push_back(p->VerAdj);
            }
        }
    }
    
}