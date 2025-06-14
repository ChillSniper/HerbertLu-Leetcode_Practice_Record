#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
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
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return Judge(root->left, root->right);
    }
private:
    bool Judge(TreeNode* l, TreeNode* r){
        if(!l && !r) return true;
        if((!l && r) || (l && !r) || (l->val != r->val)) return false;
        return Judge(l->left, r->right) && Judge(l->right, r->left);
    }
};
int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    return 0;
}