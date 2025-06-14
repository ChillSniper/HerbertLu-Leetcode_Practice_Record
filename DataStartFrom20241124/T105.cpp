#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define Test
 
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int sz = preorder.size();
        if(sz <= 0) return nullptr;
        if(sz == 1){
            TreeNode* root = new TreeNode(preorder[0]);
            return root;
        }
        int x = preorder[0], pos = -1;
        for(int i = 0;i < sz;i ++){
            if(inorder[i] == x){
                pos = i;
                break;
            }
        }
        int LfLen = pos, RiLen = sz - 1 - (pos + 1) + 1;
        vector<int> LfPre(preorder.begin() + 1, preorder.begin() + LfLen + 1);
        vector<int> RiPre(preorder.begin() + LfLen + 1, preorder.end());
        vector<int> LfInor(inorder.begin(), inorder.begin() + LfLen);
        vector<int> RiIno(inorder.begin() + LfLen + 1, inorder.end());
        TreeNode* root = new TreeNode(preorder[0]);
        root->left = buildTree(LfPre, LfInor);
        root->right = buildTree(RiPre, RiIno);
        return root;
    }
};