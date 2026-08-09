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

int maxDepth(TreeNode *root,int &x)
{
    if(root==NULL)return 0;
    int lsth=max(0,maxDepth(root->left,x));
    int rsth=max(0,maxDepth(root->right,x));
    x=max(x,lsth+rsth+root->val);
    return root->val+max(lsth,rsth);
}
    int maxPathSum(TreeNode* root) {
        int x=INT_MIN;
        int y=maxDepth(root,x);
        return x;
    }
int main()
{
    
    return 0;
}