#include <iostream>
#include <cstdio>
using namespace std;
#define Test

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
    int diameterOfBinaryTree(TreeNode* root) {
        // 所谓的求直径，就是求路径最大值
        // 而对于路径最大值求取的考虑，实际上是选取左子树最大深度 + 右子树最大深度
        // 并且注意到最终节点的选取并不一定是根节点
        MaxAns = currentAns = 0;
        Dfs(root);
        return MaxAns;
    }
    int Dfs(TreeNode* p){
        if(!p) return 0;
        int LeftDepth = Dfs(p->left);
        int RightDepth = Dfs(p->right);
        currentAns = LeftDepth + RightDepth;
        MaxAns = max(MaxAns, currentAns);
        return 1 + max(LeftDepth, RightDepth);
    }
private:
    int MaxAns = 0, currentAns;
};
int main(){
    return 0;
}