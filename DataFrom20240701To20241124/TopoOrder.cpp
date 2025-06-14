#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
#define Test
struct Edge{
    int VerAdj;
    int cost;
    Edge* link;
};
struct Vertex{
    int VerName;
    Edge* Adjacent;
};
void GetInDegree(Vertex head[], int n, int InDegree[]);
bool TopoOrder(Vertex head[], int n);
int main(){
    #ifdef Test
    freopen("file.in", "r", stdin);
    freopen("file.out", "w", stdout);
    #endif

    return 0;
}
void GetInDegree(Vertex head[], int n, int InDegree[]){
    for(int i = 0;i < n;i ++) InDegree[i] = 0;
    for(int i = 0;i < n;i ++){
        for(Edge* p = head[i].Adjacent;p;p = p->link)
            InDegree[p->VerAdj] = 1;
    }
}
bool TopoOrder(Vertex head[], int n){
    int InDegree[n] = {0};
    stack<int> st;
    GetInDegree(head, n, InDegree);
    for(int i = 0;i < n;i ++)
        if(!InDegree[i]) st.push(i);
    for(int i = 0;i < n;i ++){
        if(st.empty()) return false;
        int k = st.top(); st.pop();
        for(Edge* p = head[k].Adjacent;p;p = p->link){
            InDegree[p->VerAdj] --;
            if(!InDegree[p->VerAdj]) st.push(p->VerAdj);
        }
    }
    return false;
}