#include <iostream>
#include <cstdio>
#include <cstring>
#include <unordered_map>
#include <algorithm>
using namespace std;
#define Test

struct Node
{
    Node* Before;
    Node* Next;
    int key;
    int vl;
    Node(): Before(nullptr), Next(nullptr), key(0), vl(0){}
    Node(int k, int v, Node* b, Node* N): Before(b), Next(N), key(k), vl(v){}
};


class LRUCache {
    private:
    int size;
    int Capicity;
    Node* Head;
    Node* Tail;
    unordered_map<int, Node*> ump;
    private:
    void Move_p_ToHead(Node* p){
        Node* first = Head->Next;
        Head->Next = p; p->Before = Head;
        p->Next = first; first->Before = p;
    }
    void CutP(Node* p){
        Node* b = p->Before;
        Node* n = p->Next;
        b->Next = n;
        n->Before = b;
    }
public:
    LRUCache(int capacity):size(0), Capicity(capacity) {
        Head = new Node();
        Tail = new Node();
        Head->Next = Tail;
        Tail->Before = Head;
    }
    
    int get(int key) {
        if(ump.count(key) && ump[key] != nullptr){
            CutP(ump[key]);
            Move_p_ToHead(ump[key]);
            return ump[key]->vl;
        }
        else return -1;
    }
    void put(int key, int value) {
        if(ump.count(key)){
            Node* p = ump[key];
            p->vl = value;
            CutP(p);
            Move_p_ToHead(p);
        }
        else{
            if(size == Capicity){
                Node* deletePointer = Tail->Before;
                Node* beforeDelete = deletePointer->Before;
                ump.erase(deletePointer->key);
                delete deletePointer;
                deletePointer = nullptr;
                beforeDelete->Next = Tail;
                Tail->Before = beforeDelete;
            }
            else{
                size ++;
            }
            Node* p = new Node();
            p->key = key; p->vl = value;
            ump[key] = p;
            Move_p_ToHead(p);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    LRUCache lRUCache = *(new LRUCache(2));
    lRUCache.put(1, 1); // 缓存是 {1=1}
    lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
    cout << lRUCache.get(1) << endl;    // 返回 1
    lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
    cout << lRUCache.get(2) << endl;    // 返回 -1 (未找到)
    lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
    cout << lRUCache.get(1) << endl;    // 返回 -1 (未找到)
    cout << lRUCache.get(3) << endl;    // 返回 3
    cout << lRUCache.get(4) << endl;    // 返回 4
    return 0;
}