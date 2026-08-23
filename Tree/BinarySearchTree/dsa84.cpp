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
TreeNode *insertIntoBST(TreeNode *root, int val)
{
    TreeNode * node=new TreeNode(val);
    if(!root)return node;
    TreeNode * curr=root;

    while(curr){
        if(curr->val<=val){
            if(!curr->right){
                curr->right=node;
                break;
            }
            curr=curr->right;
        }else{
            if(!curr->left){
                curr->left=node;
                break;
            }
            curr=curr->left;
        }
    }
    return root;
}
int main()
{

    return 0;
}