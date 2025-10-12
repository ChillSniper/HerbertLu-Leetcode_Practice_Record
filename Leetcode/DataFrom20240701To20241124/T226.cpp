#include <iostream>
#include <vector>
#include <stack>
using namespace std;
#define IterateWay
//#define RecursiveWay

 // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

#ifdef RecursiveWay
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return nullptr;
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};
#endif

#ifdef IterateWay
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        stack<TreeNode*> st;
        if(!root) return root;
        TreeNode* p = root;
        while (1)
        {
            while (p)
            {
                swap(p->left, p->right);
                st.push(p);
                p = p->left;
            }
            if(st.empty()) return root;
            p = st.top()->right; st.pop();
        }
        return root;
    }
};
#endif