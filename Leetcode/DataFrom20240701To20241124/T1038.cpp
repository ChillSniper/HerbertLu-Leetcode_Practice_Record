#include <iostream>
#include <cstdio>
#include <stack>
//#define IterateWay
#define RecursiveWay
using namespace std;
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
    TreeNode* bstToGst(TreeNode* root) {
        if(!root) return root;
        bstToGst(root->right);
        root->val += pre;
        pre = root->val;
        bstToGst(root->left);
        return root;
    }
private:
    int pre = 0;
};
#endif
#ifdef IterateWay
class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        TreeNode* pre = nullptr;
        TreeNode* p = root;
        stack<TreeNode*> st;
        while (!st.empty() || p)
        {
            if(p){
                st.push(p);
                p = p->right;
            } else{
                p = st.top(); st.pop();
                if(pre) p->val += pre->val;
                pre = p;
                p = p->left;
            }
        }
        return root;
    }
};
#endif