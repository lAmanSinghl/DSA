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

TreeNode *deleteNode(TreeNode *root, int key)
{
    if (root = NULL)
    {
        return root;
    }
    if(root->val==key){
        return helper(root);
    }
    TreeNode *dummy=root;
    while(root!=NULL){
        if(root->val>key){
           if(root->left&&root->left->val==key){
            root->left=helper(root->left);
           }else{
            root=root->left;
           }
        }else{
            if(root->right&&root->right->val==key){
            root->right=helper(root->right);
           }else{
            root=root->right;
           }
        }
    }
    return dummy;
}
TreeNode *helper(TreeNode * root){
    if(root->left==NULL){
        return root->right;
    }else if(root->right==NULL){
        return root->left;
    }
    TreeNode *rightChild=root->right;
    TreeNode * lastRight=getLastright(root->left);
    lastRight->right=rightChild;
    return root->left;
}
TreeNode *getLastright(TreeNode * root){
    if(!root->right)return root;
    return getLastright(root->right);
}
int main()
{

    return 0;
}