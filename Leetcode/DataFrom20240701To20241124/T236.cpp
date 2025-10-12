#include <iostream>
#include <unordered_map>
#include <cstdio>
using namespace std;
//#define RecursiveWay
#define StoreFatherNodeWay

// Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
#ifdef StoreFatherNodeWay
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        mp[root->val] = nullptr;
        DFS(root);
        while (p)
        {
            vis[p->val] = true;
            p = mp[p->val];
        }
        while (q)
        {
            if(vis[q->val]) return q;
            q = mp[q->val];
        }
        return nullptr;
    }
private:
    void DFS(TreeNode* p){
        if(p->left){mp[p->left->val] = p; DFS(p->left);}
        if(p->right){mp[p->right->val] = p; DFS(p->right);}
    }
    unordered_map<int, TreeNode*> mp;
    unordered_map<int, bool> vis;
};
#endif

#ifdef RecursiveWay
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == p || root == q || !root) return root;
        TreeNode* l = lowestCommonAncestor(root->left, p, q);
        TreeNode* r = lowestCommonAncestor(root->right, p, q);
        if(l && r) return root;
        if(l && !r) return l;
        if(!l && r) return r;
        if(!l && !r) return nullptr;        
    }
};
#endif

int main(){
    return 0;
}