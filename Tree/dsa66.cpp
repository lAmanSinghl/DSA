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
bool isLeaf(TreeNode *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return 0;
}
void addLeftBoundry(TreeNode *root, vector<int> &res)
{
    TreeNode *curr=root->left;
    while(curr){
        if(!isLeaf(curr))res.push_back(curr->val);
        if(curr->left)curr=curr->left;
        else curr=curr->right;
    }
}
void addLeafNodes(TreeNode *root, vector<int> &res)
{
    
    if(isLeaf(root)){
        res.push_back(root->val);
        return;
    }
    if(root->left)addLeafNodes(root->left,res);
    if(root->right)addLeafNodes(root->right,res);
}
void addRightBoundry(TreeNode *root, vector<int> &res)
{
    TreeNode *curr=root->right;
    vector<int>right;
    while(curr){
        if(!isLeaf(curr))right.push_back(curr->val);
        if(curr->right)curr=curr->right;
        else curr=curr->left;
    }
    for(int i=right.size()-1;i>=0;i++){
        res.push_back(right[i]);
    }
}
vector<int> boundaryTraversal(TreeNode *root)
{
    vector<int> res;
    if (!root)return res;
    if (!isLeaf(root))res.push_back(root->val);
    addLeftBoundry(root, res);
    addLeafNodes(root, res);
    addRightBoundry(root, res);
    return res;
}
int main()
{

    return 0;
}