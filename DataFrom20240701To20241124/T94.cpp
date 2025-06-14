#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
//#define RecursiveAlgorithm
#define NonRecursiveAlgorithm
using namespace std;
// Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
#ifdef RecursiveAlgorithm
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(root){
            inorderTraversal(root->left);
            ans.push_back(root->val);
            inorderTraversal(root->right);
        }
        return ans;
    }
private:
    vector<int> ans;
};
#endif

#ifdef NonRecursiveAlgorithm
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode* p = root;
        while(1){
            while (p)
            {              
                s.push(p);
                p = p->left;
            }
            if(s.empty()) return ans;
            p = s.top();
            s.pop();
            ans.push_back(p->val);
            p = p->right;
        }
    }
private:
    vector<int> ans;
};
#endif