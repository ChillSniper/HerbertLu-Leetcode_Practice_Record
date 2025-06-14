#include <iostream>
#include <cstdio>
#include <stack>
#include <vector>
using namespace std;
#define Test
const int N = 1e3 + 10;

struct Edge
{
    int VerAdj;
    int cost;
    Edge* link;
};
struct Vertex
{
    int VerName;
    Edge* Adjacent;
};
void CriticalPath(Vertex head[], int n);
void TopoSort(Vertex head[], int Topo[], int Indegre[], int n);
void GetIndegree(Vertex head[], int n, int Indegree[]);
void VertexEarliestTime(Vertex head[], int n, int Topo[], int ve[]);
void VertexLatestTime(Vertex head[], int n, int Topo[], int ve[], int vl[]);
vector<int> ActivityStartTime(Vertex head[], int n, int Topo[], int ve[], int vl[]);


int main(){
    #ifdef Test
    freopen("file.in", "r", stdin);
    freopen("file.out", "w", stdout);
    #endif

    return 0;
}

void GetIndegree(Vertex head[], int n, int Indegree[]){
    for(int i = 1;i <= n;i ++) Indegree[i] = 0;
    for(int i = 1;i <= n;i ++){
        for(Edge* p = head[i].Adjacent;p;p = p->link){
            int k = p->VerAdj; Indegree[k] ++;
        }
    }
}
void CriticalPath(Vertex head[], int n){
    int Ve[N] = {0}, Vl[N] = {0}, Indegree[N] = {0}, Topo[N];
    GetIndegree(head, n, Indegree);
    TopoSort(head, Topo, Indegree, n);
    VertexEarliestTime(head, n, Topo, Ve);
    VertexLatestTime(head, n, Topo, Ve, Vl);
    vector<int> ans = ActivityStartTime(head, n, Topo, Ve, Vl);
}

void TopoSort(Vertex head[], int Topo[], int Indegree[], int n){
    stack<int> st;
    int TopoIndex = 0;
    for(int i = 1;i <= n;i ++)
        if(!Indegree[i]) st.push(i);
    for(int i = 1;i <= n;i ++){
        if(st.empty()) return;
        int k = st.top(); st.pop();
        Topo[TopoIndex ++] = k;
        for(Edge* p = head[k].Adjacent;p;p = p->link){
            Indegree[p->VerAdj] --;
            if(!Indegree[p->VerAdj]) st.push(p->VerAdj);
        }
    }
}

void VertexEarliestTime(Vertex head[], int n, int Topo[], int ve[]){
    for(int i = 1;i <= n;i ++) ve[i] = 0;
    // 此处求取各顶点最早发生时间要按照拓扑排序的顶点顺序！！！
    for(int i = 1;i <= n;i ++){
        int k = Topo[i];
        for(Edge* p = head[k].Adjacent;p;p = p->link){
            ve[p->VerAdj] = max(ve[p->VerAdj], ve[k] + p->cost);
        }
    }
}

void VertexLatestTime(Vertex head[], int n, int Topo[], int ve[], int vl[]){
    for(int i = 1;i <= n;i ++) vl[i] = ve[Topo[n]];
    for(int i = n;i >= 1;i --){
        int k = Topo[i];
        for(Edge* p = head[k].Adjacent;p;p = p->link){
            vl[p->VerAdj] = min(vl[p->VerAdj], vl[k] - p->cost);
        }
    }
}

vector<int> ActivityStartTime(Vertex head[], int n, int Topo[], int ve[], int vl[]){
    vector<int> ans;
    ans.push_back(Topo[1]);
    for(int i = 1;i <= n;i ++){
        int k = Topo[i];
        for(Edge* p = head[k].Adjacent;p;p = p->link){
            if(vl[p->VerAdj] - p->cost == ve[k]) ans.push_back(p->VerAdj);
        }
    }
    return ans;
}