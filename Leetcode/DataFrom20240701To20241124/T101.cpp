#include <iostream>
#include <cstdio>
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
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return CompareTwoNodes(root->left, root->right);
    }
    bool CompareTwoNodes(TreeNode* L, TreeNode* R){
        if(!L && !R) return true;
        if(!L && R || !R && L) return false;
        if(L->val != R->val) return false;
        bool Judge1 = CompareTwoNodes(L->left, R->right);
        bool Judge2 = CompareTwoNodes(L->right, R->left);
        return Judge1 && Judge2;
    }
}; 