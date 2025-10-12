#include <iostream>
#include <cstdio>
using namespace std;
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

void GetInDegree(Vertex Head[], int n, int InDegree[]);

int main(){

    return 0;
}

void GetInDegree(Vertex Head[], int n, int InDegree[]){
    for(int i = 0;i < n;i ++) InDegree[i] = 0;
    for(int i = 0;i < n;i ++){
        for(Edge* p = Head[i].adjacent;p;p = p->link){
            InDegree[p->VerAdj] ++;
        }
    }
}