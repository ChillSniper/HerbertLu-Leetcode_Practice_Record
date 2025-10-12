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
    int maxDepth(TreeNode* root) {
        Dfs(root, 0);
        return Depth;
    }
private:
    void Dfs(TreeNode* root, int cur){
        if(!root) return ;
        cur ++;
        Depth = max(cur, Depth);
        Dfs(root->left, cur);
        Dfs(root->right, cur);
    }
    int Depth = 0;
};
int main(){
    #ifdef Test
    #endif
    return 0;
}