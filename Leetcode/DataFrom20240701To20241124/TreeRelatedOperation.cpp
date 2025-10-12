#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* Left;
    TreeNode* Right;
    TreeNode(): val(0), Left(nullptr), Right(nullptr){}
    TreeNode(int num): val(num), Left(nullptr), Right(nullptr){}
};

TreeNode* FindFather(TreeNode* root, TreeNode* p){
// the funtion used to find the father node of p
    if(!root || root == p) return nullptr;
    // recursive need the situation of judging
    if(root->Left == p || root->Right == p) return root;
    TreeNode* father = FindFather(root->Left, p);
    if(!father) return father;
    else return FindFather(root->Right, p);
}

TreeNode* ConformToData(TreeNode* root, int data){
    if(!root) return nullptr;
    if(root->val == data) return root;
    TreeNode* p = ConformToData(root->Left, data);
    if(!p) return p;
    return ConformToData(root->Right, data);
}

void DeleteTree(TreeNode* root){
    if(!root) return ;
    DeleteTree(root->Left);
    DeleteTree(root->Right);
    delete root;
    root = nullptr; // Prevent memory leaks!!!
}

void DeleteSubTree(TreeNode* root, TreeNode* p){
    if(!root) return;
    if(root == p){DeleteTree(root); return;}
    TreeNode* Father = FindFather(root, p);
    Father->Left = Father->Right = nullptr;
    DeleteTree(p);
}

TreeNode* BuildTree(){
    int data; scanf("%d", &data);
    if(data == 0) return nullptr;
    TreeNode* p = new TreeNode(data);
    p->val = data;
    p->Left = BuildTree();
    p->Right = BuildTree();
    return p;
}

TreeNode* CopyTree(TreeNode* root){
    if(!root) return nullptr;
    TreeNode* NewLeft = CopyTree(root->Left);
    TreeNode* NewRight = CopyTree(root->Right);
    TreeNode* NewRoot = new TreeNode(root->val);
    NewRoot->Left = NewLeft;
    NewRight->Right = NewRight;
    return NewRoot;
}

int CalculateTreeNode(TreeNode* root){
    if(!root) return 0;
    return 1 + CalculateTreeNode(root->Left) + CalculateTreeNode(root->Right) + 1;
}

int CalculateTreeDepth(TreeNode* root){
    if(!root) return -1;
    int LeftDepth = CalculateTreeDepth(root->Left);
    int RightDepth = CalculateTreeDepth(root->Right);
    return (LeftDepth > RightDepth) ? LeftDepth + 1 : RightDepth + 1;
}

TreeNode* FindFirstNodeOfInOrderSequence(TreeNode* root){
    if(!root) return nullptr;
    TreeNode* p = root;
    while (p->Left)
    {   
        p = p->Left;
    }
    return p;
}

TreeNode* FindLastNodeOfInorderSequence(TreeNode* root){
    if(!root) return nullptr;
    TreeNode* p = root;
    while (p->Right) p = p->Right;
    return p;
}

TreeNode* FindLastNodeOfPreOrderSequence(TreeNode* root){
    if(!root) return root;
    TreeNode* p = root;
    while (p)
    {
        if(p->Right) p = p->Right;
        else if(p->Left) p = p->Left;
        else return p; // 注意p应当在循环体内而不是在循环体外返回，否则会造成死循环
    }
    return nullptr;
}

TreeNode* FindFirstNodeOfPostOrderSequence(TreeNode* root){
    if(!root) return root;
    TreeNode* p = root;
    while (p)
    {
        if(p->Left) p = p->Left;
        else if(p->Right) p = p->Right;
        else return p;
    }
    return nullptr;
}

void FindPath(TreeNode* root, int Data[], int k){
    if(!root) return;
    Data[k] = root->val;
    if(root->Left == nullptr && root->Right == nullptr){
        for(int i = 0;i <= k;i ++){
            printf("%d", Data[i]);
        }
        return ;
    }
    FindPath(root->Left, Data, k + 1);
    FindPath(root->Right, Data, k + 1);
}