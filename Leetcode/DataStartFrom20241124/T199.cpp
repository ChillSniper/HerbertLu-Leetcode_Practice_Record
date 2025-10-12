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
        vector<int> rightSideView(TreeNode* root) {
            deque<TreeNode*> dq;
            if(!root) return {};
            dq.push_back(root);
            while (dq.size())
            {
                int sz = dq.size();
                for(int i = 0;i < sz - 1;i ++){
                    TreeNode* p = dq.front(); dq.pop_front();
                    if(p->left) dq.push_back(p->left);
                    if(p->right) dq.push_back(p->right);
                }
                TreeNode* p = dq.front(); dq.pop_front();
                ans.push_back(p->val);
                if(p->left) dq.push_back(p->left);
                if(p->right) dq.push_back(p->right);
            }
            return ans;
        }
    private:
        vector<int> ans;
};
int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    return 0;
}