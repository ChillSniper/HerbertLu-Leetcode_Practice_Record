#include <iostream>
#include <cstdio>
using namespace std;

struct Edge{
    int cost;
    int VerAdj;
    Edge* link;
};
struct Vertex{
    int VerName;
    Edge* adjacent;
};
bool DfsForNoDirectionGraphRingJudge(Vertex* head, int* visited, int u, int pre);
bool HasCircleOfDirectedGraph(Vertex* head, int visited[], int u);
int main(){

    return 0;
}
bool DfsForNoDirectionGraphRingJudge(Vertex* head, int* visited, int u, int pre){
    visited[u] = 1;
    for(Edge* p = head[u].adjacent;p;p = p->link){
        if(visited[p->VerAdj] && pre != p->VerAdj) return true;
        if(!visited[p->VerAdj]){
            pre = u;
            DfsForNoDirectionGraphRingJudge(head, visited, p->VerAdj, pre);
        }
    }
    return false;
}

bool HasCircleOfDirectedGraph(Vertex* head, int visited[], int u){
    visited[u] = 1;
    for(Edge* p = head[u].adjacent;p;p = p->link){
        if(!visited[p->VerAdj]){
            visited[p->VerAdj] = 1;
            HasCircleOfDirectedGraph(head, visited, p->VerAdj);
        } else if(visited[p->VerAdj] == 1) return true;
    }
    visited[u] = 2;
    return false;
}