#include <iostream>
#include <cstdio>
#include <unordered_map>
#include <vector>
using namespace std;
//#define RecursiveWay
#define FindFatherWay
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#ifdef FindFatherWay
// stl能用就用...
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        father[root] = nullptr;
        Dfs(root);
        while (p)
        {
            vis[p] = 1;
            p = father[p];
        }
        while (q)
        {
            if(vis[q]) return q;
            q = father[q];
        }
        return nullptr;
    }
    void Dfs(TreeNode* p){
        if(!p) return ;
        vis[p] = 0;
        if(p->left) father[p->left] = p, Dfs(p->left);
        if(p->right) father[p->right] = p, Dfs(p->right);
    }
private:
    unordered_map<TreeNode*, int> vis;
    unordered_map<TreeNode*, TreeNode*> father;
};
#endif
#ifdef RecursiveWay
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return dfs(p, q, root);
    }
private:
    TreeNode* dfs(TreeNode* p, TreeNode* q, TreeNode* cur){
        // 其实这个问题的根本在于左右子树包不包含节点p或者q
        if(!cur) return nullptr;
        if(cur == p || cur == q) return cur;
        TreeNode* l = dfs(p, q, cur->left);
        TreeNode* r = dfs(p, q, cur->right);
        if(l && !r) return l;
        if(!l && r) return r;
        if(l && r) return cur;
        return nullptr;
    }
};
#endif
int main(){
    return 0;
}