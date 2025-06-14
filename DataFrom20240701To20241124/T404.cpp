#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
#define RecursiveWay
#define IterateWay

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#ifdef IterateWay
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        TreeNode* p = root;
        int sum = 0;
        stack<TreeNode*> stk;
        while (p || !stk.empty())
        {
            if(p){
                stk.push(p);
                p = p->left;
            } else {
                p = stk.top(); stk.pop(); 
                if(p->left && !p->left->left && !p->left->right) sum += p->left->val;
                p = p->right;
            }
        }
        return sum;
    }
};
#endif

#ifdef RecursiveWay 
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        if(root && root->left && !root->left->left && !root->left->right) 
            return root->left->val + sumOfLeftLeaves(root->right);
        return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};
#endif

int main(){
    freopen("file.in", "r", stdin);
    freopen("file.out", "w", stdout);

    return 0;
}