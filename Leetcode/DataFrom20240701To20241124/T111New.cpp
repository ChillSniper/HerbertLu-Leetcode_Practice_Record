#include <iostream>
#include <deque>
using namespace std;
//#define PostOrder
//#define PreOrder
#define LevelTravesal

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#ifdef PostOrder
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        int Ld = minDepth(root->left), rd = minDepth(root->right);
        if(!root->left) return 1 + rd;
        if(!root->right) return 1 + Ld;
        return 1 + min(Ld, rd);
    }
};
#endif
#ifdef PreOrder
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        DFS(root, 1);
        return result;
    }
    void DFS(TreeNode* root, int depth){
        if(!root) return;
        if(!root->left && !root->right){result = min(result, depth);}
        if(root->left){DFS(root->left, depth + 1);}
        if(root->right){DFS(root->right, depth + 1);}
    }
private:
    int result = 0x3f3f3f3f;
};
#endif
#ifdef LevelTravesal
class Solution {
public:
    int minDepth(TreeNode* root) {
        int Level = 0;
        if(!root) return Level;
        deque<TreeNode*> dq;
        dq.push_back(root);
        while (!dq.empty())
        {
            int size = dq.size();
            Level ++;
            while (size --)
            {
                TreeNode* p = dq.front();
                dq.pop_front();
                if(!p->left && !p->right) return Level;
                if(p->left) dq.push_back(p->left);
                if(p->right) dq.push_back(p->right);
            }
        }
        return Level;
    }
};
#endif