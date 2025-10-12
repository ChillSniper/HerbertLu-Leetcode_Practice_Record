#include <iostream>
#include <deque>    
using namespace std;
//#define LevelTravesal
//#define PostOrder
#define DetermineFullBinaryTree

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#ifdef DetermineFullBinaryTree
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int ld = 0, rd = 0;
        TreeNode* p =root;
        while (p)
        {
            ld ++;
            p = p->left;
        }
        p = root;
        while (p)
        {
            rd ++;
            p = p->right;
        }
        if(ld == rd) {return (2 << (ld - 1)) - 1;}
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};
#endif

#ifdef PostOrder
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

};
#endif

#ifdef LevelTravesal
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int num = 0;
        deque<TreeNode*> dq;
        dq.push_back(root);
        while (!dq.empty())
        {
            int size = dq.size();
            num += size;
            while (size --)
            {
                TreeNode* p = dq.front(); dq.pop_front();
                if(p->left) dq.push_back(p->left);
                if(p->right) dq.push_back(p->right);
            }
        }
        return num;
    }
};
#endif
int main(){
    return 0;
}
