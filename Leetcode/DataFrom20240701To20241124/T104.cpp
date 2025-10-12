#include <iostream>
#include <cstdio>
#include <vector>
#include <deque>
using namespace std;

//  Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    int maxDepth(TreeNode* root) {
        DFS(root, 1);
        return depth;
    }
    void DFS(TreeNode* p, int h){
        if(!p) return;
        depth = max(h, depth);
        DFS(p->left, h + 1);
        DFS(p->right, h + 1);
    }
private:
    int depth = 0;
};