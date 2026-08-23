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

TreeNode *buildTree(vector<int> &preorder,int n,int m ,vector<int> &inorder,int p,int q,map<int,int>mpp){
    if(n>m||p>q)return NULL;
    TreeNode * root=new TreeNode(preorder[n]);
    int inRoot=mpp[root->val];
    int numsleft=inRoot-p;
    root->left=buildTree(preorder,n+1,n+numsleft,inorder,p,inRoot-1,mpp);
    root->right=buildTree(preorder,n+numsleft+1,m,inorder,inRoot+1,q,mpp);
    return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    map<int,int>mpp;
    for(int i=0;i<inorder.size();i++){
        mpp[inorder[i]]=i;
    }
    TreeNode * root=buildTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mpp);
    return root;
}


int main()
{

    return 0;
}