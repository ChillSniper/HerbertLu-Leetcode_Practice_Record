#include <iostream>
#include <cstdio>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode():val(0), next(nullptr){}
    ListNode(int x):val(x), next(nullptr){}
    ListNode(int x, ListNode* p):val(x), next(p){}
};

struct Edge{
    int VerAdj;
    int cost;
    Edge* link;
};
struct Vertex{
    int VerName;
    Edge* adjacent;
};

int FindPath(Vertex head[], int n, int u, int v, int L, int m, ListNode* PathList[]);
bool Dfs(int visited[], ListNode* node, Vertex head[], int u, int v, int L, int m);

int main(){
    freopen("file.in", "r", stdin);
    freopen("file.out", "w", stdout);

    return 0;
}

int FindPath(Vertex head[], int n, int u, int v, int L, int m, ListNode* PathList[]){
    int cnt = 0;
    int visited[n] = {0};
    visited[u] = 1;
    for(Edge* p = head[u].adjacent;p;p = p->link){
        if(p->VerAdj == v || visited[p->VerAdj]) continue;
        ListNode* node = new ListNode(u);
        ListNode* root = new ListNode(0, node);
        visited[p->VerAdj] = 1;
        if(Dfs(visited, root, head, p->VerAdj, v, L - p->cost, m - 1)) PathList[cnt ++] = root;
        visited[p->VerAdj] = 0;
    }
    return cnt;
}
bool Dfs(int visited[], ListNode* node, Vertex head[], int u, int v, int L, int m){
    if(L < 0 || m < 0 || u == v) return false;
    if(L == 0 && m >= 0){
        return true;
    }
    for(Edge* i = head[u].adjacent;i;i = i->link){
        if(i->VerAdj == v || visited[i->VerAdj]) continue;
        visited[i->VerAdj] = 1;
        // �������ܴ����˵�����ڵ��ж���·��������ͨ����ô��һ�Ľڵ�node�����·����ʧ
        // ��ʵӦ����һ��vector<int>��������飬Ȼ����FindPath�������洴������
        // �ȸ��ðɣ�������д
        
    }
}