#include <iostream>
#include <cstdio>
#include <stack>
#include <list>
using namespace std;
//#define Recursive
#define NonRecursive
#define Test
struct Vertex{
    int VerName;
    Edge* adjacent;
};
struct Edge{
    int VerAdj;
    int cost;
    Edge* link;
};

void BFS(Vertex* head, int k, int n, int visited[]);
void DFS(Vertex* head, int n, int visited[]);
void vis(int n);

int main(){
    #ifdef Test
    freopen("file.in", "r", stdin);
    freopen("file.out", "w", stdout);
    #endif
    
    return 0;
}

void BFS(Vertex* head, int k, int n, int visited[]){
    deque<int> dq;
    for(int i = 0;i < n;i ++) visited[i] = 0;
    vis(k); visited[k] = 1;
    dq.push_back(k);
    while (!dq.empty())
    {
        k = dq.front(); dq.pop_front();
        for(Edge* p = head[k].adjacent;p;p = p->link){
            if(!visited[p->VerAdj]){
                vis(p->VerAdj);
                visited[p->VerAdj] = 0;
                dq.push_back(p->VerAdj);
            }
        }
    }
}

#ifdef NonRecursive
void DFS(Vertex* head, int k, int visited[]){
    stack<int> st;
    st.push(k);
    while (!st.empty())
    {
        k = st.top(); st.pop();
        vis(k); visited[k] = 1;
        for(Edge* p = head[k].adjacent;p;p = p->link){
            if(!visited[p->VerAdj]) st.push(p->VerAdj);
        }
    }
}
#endif

#ifdef Recursive
void DFS(Vertex* head, int k, int visited[]){
    vis(k); visited[k] = 1;
    for(Edge* p = head[k].adjacent;p;p = p->link){
        if(!visited[p->VerAdj]) DFS(head, p->VerAdj, visited);
    }
}
#endif