#include <bits/stdc++.h>
using namespace std;

#define Test

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_set<Node*> vis;
        unordered_map<int, Node*> Comparision_table;
        deque<Node*> dq;
        dq.push_back(node);
        Node* root = new Node(node->val);
        Comparision_table[node->val] = root;
        while (dq.size())
        {
            Node* cur = dq.front();
            dq.pop_front();
            if(vis.count(cur)) {
                continue;
            }
            vis.insert(cur);
            
            Node* truly_op = nullptr;
            if(Comparision_table.count(cur->val)) {
                truly_op = Comparision_table[cur->val];
            }
            else {
                truly_op = new Node(cur->val);
                Comparision_table[cur->val] = truly_op;
            }
            
            vector<Node*>& neibour_cur = cur->neighbors;

            for (auto& item : neibour_cur) {
                Node* p = nullptr;
                if(Comparision_table.count(item->val)) {
                    p = Comparision_table[item->val];
                }
                else {
                    p = new Node(item ->val);
                    Comparision_table[item->val] = p; 
                }
                truly_op->neighbors.push_back(p);
                dq.push_back(item);
            }
        }
        return root;
    }
};