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

TreeNode *bstFromPreorder(vector<int> &preorder)
{
    int i=0;
    return helper(preorder,i,INT_MAX);
}
TreeNode *helper(vector<int> &preorder,int &i,int Upperbound){
    if(i>preorder.size()||preorder[i]>Upperbound)return NULL;
    TreeNode *node=new TreeNode(preorder[i++]);
    node->left=helper(preorder,i,node->val);
    node->right=helper(preorder,i,Upperbound);
    return node;
}

int main()
{

    return 0;
}