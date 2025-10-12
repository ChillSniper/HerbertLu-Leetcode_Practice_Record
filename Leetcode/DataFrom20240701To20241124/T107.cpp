#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
using namespace std;
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> ans;
        int i = 0, Len = 1;
        nodes[i ++] = root;
        RecordLen.push_back(Len);
        while (Len > 0)
        {
            int st = i - Len;
            RecordLen.push_back(Len);
            for(int j = st;j < st + Len;j ++){
                if(nodes[j]->left){nodes[i ++] = nodes[j]->left;}
                if(nodes[j]->right){nodes[i ++] = nodes[j]->right;}
            }
            Len = i - (st + Len);
        }
        int AllLen = RecordLen.size();
        for(int k = AllLen - 1;k >= 0;k --){
            int st = i - RecordLen[k];
            i = st;
            vector<int> tmp;
            for(int j = st;j < st + RecordLen[k];j ++){
                tmp.push_back(nodes[j]->val);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
private:
    vector<int> RecordLen;
    TreeNode* nodes[2010];
};