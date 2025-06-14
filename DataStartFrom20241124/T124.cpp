#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
const int Min = 0xc0c0c0c0;
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        DfsForPath(root);
        return ans;
    }
private:
    int DfsForPath(TreeNode* root){
        if(!root) return 0;
        int ls = DfsForPath(root->left);
        int rs = DfsForPath(root->right);
        int t = root->val;
        if(ls > 0) t += ls;
        if(rs > 0) t += rs;
        ans = max(ans, t);
        int k = max(ls, rs) > 0 ? max(ls, rs) : 0;
        return root->val + k;
    }
    int ans = Min;
};