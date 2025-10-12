#include <iostream>
#include <deque>
#include <vector>
using namespace std;

//#define Way1UsingDeque
#define Way2BuildDynamic

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

#ifdef Way2BuildDynamic
class Solution {
public:
    Node* connect(Node* root) {
        Node* HeadLeft = root;
        while (HeadLeft)
        {
            Node* p = HeadLeft;
            while (p)
            {
                if(p->left)
                p->left->next = p->right;
                if(p->next && p->right)
                p->right->next = p->next->left;
                p = p->next;
            }
            HeadLeft = HeadLeft->left;
        }
        return root;
    }
};
#endif

#ifdef Way1UsingDeque
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        deque<Node*> dq;
        dq.push_back(root);
        while(!dq.empty()){
            int size = dq.size();
            while (size --)
            {
                Node* p = dq.front();
                dq.pop_front();
                if(size) p->next = dq.front();
                else p->next = nullptr;
                if(p->left) dq.push_back(p->left);
                if(p->right) dq.push_back(p->right);
            }
        }
        return root;
    }
};
#endif