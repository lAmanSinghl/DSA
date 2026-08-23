#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
    bool checkTree(TreeNode* root) {
        if(!root)return true;
        if(!root->left&&!root->right)return true;
        if((root->left?root->left->val:0)+(root->right?root->right->val:0)==root->val&&checkTree(root->left)&&checkTree(root->right))return true;
        return false;

    }
    void changeTree(TreeNode* root){
        if(root==NULL)return;
        int child=0;
        if(root->left)child+=root->left->val;
        if(root->right)child+=root->right->val;
        if(child>=root->val)root->val=child;
        else{
            if(root->left)root->left->val=root->val;
            if(root->right)root->right->val=root->val;
        }
        changeTree(root->left);
        changeTree(root->right);
        int tot=0;
        if(root->left)tot+=root->left->val;
        if(root->right)tot+=root->right->val;
        if(root->left || root->right)root->val=tot;

    }
int main()
{
    
    return 0;
}