#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
#define Test

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, int> ori;
        unordered_map<int, Node*> AfChange;
        int index = 0;
        Node* PreHead = new Node(0), *p = PreHead, *q = head;
        while (q)
        {
            p->next = new Node(q->val);
            ori[q] = index;
            AfChange[index] = p->next;
            index ++;
            p = p->next;
            q = q->next;
        }
        q = head;
        p = PreHead->next;
        while (q)
        {
            Node* tmp = q->random;
            if(!tmp){
                p->random = nullptr;
            }
            else{
                int x = ori[tmp];
                p->random = AfChange[x];
            }
            q = q->next;
            p = p->next;
        }
        return PreHead->next;
    }
};

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif

    return 0;
}