#include <iostream>
#include <cstdio>
#include <vector>
#include <deque>
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
    vector<vector<int>> levelOrder(Node* root) {
        deque<Node*> dq;
        if(!root) return {};
        vector<vector<int>> ans;
        dq.push_back(root);
        while (!dq.empty())
        {
            int Len = dq.size();
            vector<int> tmp;
            while (Len --)
            {
                Node* p = dq.front();
                dq.pop_front();
                tmp.push_back(p->val);
                int s = p->children.size();
                for(int i = 0;i < s;i ++) dq.push_back(p->children[i]);
            }
            ans.push_back(tmp);
        }
        return ans;        
    }
};

int main(){

    return 0;
}