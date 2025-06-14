#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;

//  Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* Pre = nullptr, *Cur = root;
        stack <TreeNode*> st;
        while (1)
        {
            while (Cur)
            {
                st.push(Cur);
                Cur = Cur->left;
            }
            if(st.empty()) return nullptr;
            Cur = st.top();
            st.pop();
            if(Pre == p && Cur) return Cur;
            Pre = Cur;
            Cur = Cur->right;
        }
        return nullptr;
    }
};
int main(){
    freopen("file.in", "r", stdin);
    freopen("file.out", "w", stdout);
    
    return 0;
}