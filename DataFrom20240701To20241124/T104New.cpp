#include <iostream>

//#define PostOrder
#define PreOrder

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

#ifdef PostOrder
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int LD = maxDepth(root->left);
        int Rd = maxDepth(root->right);
        return 1 + max(LD, Rd);
    }
};
#endif

#ifdef PreOrder
class Solution {
public:
    int maxDepth(TreeNode* root) {
        
    }
};
#endif

 int main(){
    freopen("file.in", "r", stdin);
    freopen("file.out", "w", stdout);
    return 0;
 }