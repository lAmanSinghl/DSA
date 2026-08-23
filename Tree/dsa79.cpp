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

TreeNode *buildTree(vector<int> &postorder,int n,int m ,vector<int> &inorder,int p,int q,map<int,int>&mpp){
    if(n>m||p>q)return NULL;
    TreeNode * root=new TreeNode(postorder[m]);
    int inRoot=mpp[root->val];
    int numsleft=inRoot-p;
    root->left=buildTree(postorder,n,n+numsleft-1,inorder,p,inRoot-1,mpp);
    root->right=buildTree(postorder,n+numsleft,m-1,inorder,inRoot+1,q,mpp);
    return root;
}

TreeNode *buildTree(vector<int> &postorder, vector<int> &inorder)
{
    map<int,int>mpp;
    for(int i=0;i<inorder.size();i++){
        mpp[inorder[i]]=i;
    }
    TreeNode * root=buildTree(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,mpp);
    return root;
}
int main()
{
    
    return 0;
}