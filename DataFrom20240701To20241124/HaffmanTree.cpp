#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct HaffmanNode{
    char data;
    int weight;
    HaffmanNode* left, *right;
};

class Solution{
public:
    HaffmanNode* CreateHaffmanTree(HaffmanNode* H[], int n){
        for(int i = 0;i < n;i ++){
            scanf("%d%c", &H[i]->weight, &H[i]->weight);
            H[i]->left = H[i]->right = nullptr;
        }
        sort(H, H + n, ComPare);
        for(int i = 0;i < n - 1;i ++){
            HaffmanNode* tmp = new HaffmanNode();
            tmp->weight = H[i]->weight + H[i + 1]->weight;
            tmp->left = H[i]; tmp->right = H[i + 1];
            int j = i + 2;
            while (j < n && H[j]->weight < tmp->weight)
            {
                j ++;
            }
            H[j - 1] = tmp;
        }
        return H[n - 1];
    }
    bool ComPare(HaffmanNode* a, HaffmanNode* b){
        return a->weight < b->weight;
    }
private:
    int WPL = 0;
};


int main(){

    return 0;
}