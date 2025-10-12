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
    vector<vector<int>> levelOrder(TreeNode* root) {
        deque<TreeNode*> dq;
        vector<vector<int>> ans;
        dq.push_back(root);
        while (dq.size())
        {
            int sz = dq.size();
            vector<int> tmp;
            for(int i = 0;i < sz;i ++){
                TreeNode* p = dq.front(); dq.pop_front();
                tmp.push_back(p->val);
                if(p->left) dq.push_back(p->left);
                if(p->right) dq.push_back(p->right);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};

int main(){
    #ifdef Test
    
    #endif
    return 0;
}