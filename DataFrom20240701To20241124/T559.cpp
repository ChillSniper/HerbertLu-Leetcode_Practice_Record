#include <iostream>
#include <vector>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
public:
    int maxDepth(Node* root) {
        if(!root) return 0;
        int size = root->children.size();
        int depth = 0;
        for(int i = 0;i < size;i ++) depth = max(depth, maxDepth(root->children[i]));
        depth ++;
        return depth;
    }
};