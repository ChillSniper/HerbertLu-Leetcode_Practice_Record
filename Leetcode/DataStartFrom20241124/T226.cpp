#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
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
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return nullptr;
        if(root && !root->left && !root->right) return root;
        TreeNode* L = invertTree(root->left);
        TreeNode* R = invertTree(root->right);
        root->left = R;
        root->right = L;
        return root;    
    }
private:

};

int main(){
    #ifdef Test

    #endif
    return 0;
}