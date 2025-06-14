#include <bits/stdc++.h>
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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        Dfs(root);
        deque<TreeNode*> dq;
        dq.push_back(root);
        set<TreeNode*> st;
        while (dq.size())
        {
            st.clear();
            int sz = dq.size();
            for(int i = 0;i < sz;i ++){
                TreeNode* p = dq.front(); dq.pop_front();
                st.insert(p);
                if(p->left)
                    dq.push_back(p->left);
                if(p->right)
                    dq.push_back(p->right);
            }
        }
        while (st.size() > 1)
        {
            int sz = st.size();
            set<TreeNode*> tmp;
            for(auto i = st.begin();i != st.end();i ++){
                TreeNode* p = *i;
                if(father[p]){
                    tmp.insert(father[p]);
                }
            }
            st = tmp;
        }
        return *st.begin();
    }
private:
    unordered_map<TreeNode*, TreeNode*> father;
    void Dfs(TreeNode* root){
        if(!root)
            return ;
        if(root->left){
            father[root->left] = root;
            Dfs(root->left);
        }
        if(root->right){
            father[root->right] = root;
            Dfs(root->right);
        }
    }
};

int main(){
    #ifdef Test
        freopen("file..in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    return 0;
}