/**
*
* Code By ShengLi Chen
* 2024-11-02 For DataStructure Homework Lab 3-4 Week 
* 
*
**/

#include<iostream>
#include<cassert>
using namespace std;
const int maxsize = 1e4 + 10;

#define Test

template <class T>
class Stack {
public:
	bool empty() { return top == -1; }
	bool full() { return top == maxsize - 1; }
	void push(T K) { assert(!full()); A[++top] = K; }
	T pop() { assert(!empty()); return A[top--]; }
	T peek() { assert(!empty()); return A[top]; }
private:
	T A[maxsize];
	int top = -1;
};



struct TreeNode
{
	int data;
	int current;
	int currentlen;
	TreeNode* left;
	TreeNode* right;
};


TreeNode* CreateBinTree()
{
	int k;
	cin >> k;
	if (k == 0)
		return NULL;
	TreeNode* t = new TreeNode;
	t->data = k;
	t->current = k;
	t->currentlen = 1;
	t->left = CreateBinTree();
	t->right = CreateBinTree();
	return t;
}

int maxi = 0;
TreeNode* StartNode;
TreeNode* EndNode;
int maxlen = 0;

TreeNode* Father(TreeNode* root, TreeNode* p) {
	//在以root为根的二叉树中找p的父结点，返回指针
	if (root == NULL || p == root)
		return NULL; //根空或p为根
	if (root->left == p || root->right == p) //root即p的父结点
		return root;
	TreeNode* fa = Father(root->left, p);//在左子树中找p父
	if (fa != NULL)
		return fa;
	return Father(root->right, p); //在root右子树中找p父
}

void PreOrder(TreeNode* t, TreeNode* root)
{
	Stack<TreeNode*> S;
	TreeNode* p = t;
	while (true)
	{
		while (p != NULL)
		{
			TreeNode* FA = Father(root, p);
			if (FA != NULL)
			{
				if (FA->current > 0)
				{
					p->current = p->data + FA->current;
					p->currentlen = FA->currentlen + 1;
				}
				else 
				{
					p->current = p->data;
					p->currentlen = 1;
				}
			}
			if (p->current > maxi || (p->current == maxi && p->currentlen < maxlen))
			{
				maxi = p->current;
				maxlen = p->currentlen;
				EndNode = p;
				if (FA->current <= 0)
					StartNode = p;
			}
			//****************//
			S.push(p);
			p = p->left;
		}
		if (S.empty())
			return;
		p = S.pop();
		p = p->right;
	}
}

int main()
{
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
	TreeNode* root = CreateBinTree();
	maxi = root->current;
	StartNode = root;
	EndNode = root;
	maxlen = 1;
	PreOrder(root, root);
	cout << maxi<<endl;
	//cout << StartNode->data << " " << EndNode->data<<endl;
	int answer[5000];
	TreeNode* current = EndNode;
	answer[0] = current->data;
	int i = 0;
	if (current == StartNode)
		cout << current->data<<" ";
	else
	{
		while (Father(root, current) != StartNode)
		{
			i++;
			current = Father(root, current);
			answer[i] = current->data;
		}
		cout << StartNode->data << " ";
		for (int j = i; j >= 0; j--)
		{
			cout << answer[j] << " ";
		}
	}
	return 0;
}