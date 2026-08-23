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
int leftsubtreeHeight(TreeNode* root){
    int i=0;
    while(root){
        i++;
        root=root->left;
    }
    return i;
}int rightsubtreeHeight(TreeNode* root){
    int i=0;
    while(root){
        i++;
        root=root->right;
    }
    return i;
}
int countNodes(TreeNode *root)
{
    if(!root)return 0;

    int lh=leftsubtreeHeight(root);
    int rh=rightsubtreeHeight(root);
    if(lh==rh)return (1<<lh)-1;
    return 1+countNodes(root->left)+countNodes(root->right);


}

int main()
{

    return 0;
}