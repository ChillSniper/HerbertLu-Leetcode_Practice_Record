#include <iostream>
#include <cstdio>
//#define RecursiveWay
#define IterateWay
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
#ifdef IterateWay
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        TreeNode* p = root, *pre = nullptr;
        //  写了这么多代码还是没彻底搞明白指针的作用和实际意义 实际上，前一个指针指向这个指针（即这个结构体的地址）
        // 但是，这个结构体现在没了，变成了一个新的值（尽管还是同类型）
        while (p)
        {
            if(p->val == key){
                if(!p->left && !p->right){ delete p; p = nullptr;}
                else if(p->left && !p->right){ TreeNode* tmp = p->left; delete p; p = tmp;}
                else if(!p->left && p->right){ TreeNode* tmp = p->right; delete p; p = tmp;}
                else if(p->left && p->right){
                    TreeNode* tmp = p->left;
                    while (tmp->right)
                    {
                        tmp = tmp->right;
                    }
                    tmp->right = p->right;
                    tmp = p->left;
                    delete p;
                    p = tmp;
                }
                if(pre){
                    if(pre->val > key) pre->left = p;
                    else pre->right = p;
                } else {
                    root = p;
                }
                break;
            } 
            else if(p->val > key) pre = p, p = p->left;
            else if(p->val < key) pre = p, p = p->right;
        }
        return root;
    }
};
#endif

#ifdef RecursiveWay
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        if(root->val > key) root->left = deleteNode(root->left, key);
        if(root->val < key) root->right = deleteNode(root->right, key);
        if(root->val == key){
            if(!root->left && !root->right){
                root = nullptr;
            } else if(root->left && !root->right){
                root = root->left;
            } else if(!root->left && root->right){
                root = root->right;
            } else{
                TreeNode* p = root->left;
                while (p->right)
                {
                    p = p->right;
                }
                p->right = root->right;
                root->right = nullptr;
                root = root->left;
            }
        }
        return root;
    }
};
#endif

int main(){
    return 0;
}