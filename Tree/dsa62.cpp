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
int helperfunction(TreeNode *root, int &maxi)
{

    if (root == NULL)
        return 0;
    int lsth = helperfunction(root->left, maxi);
    int rsth = helperfunction(root->right, maxi);
    maxi = max(maxi, lsth + rsth);
    return 1 + max(lsth, rsth);
}
int diameterOfBinaryTree(TreeNode *root)
{
    int maxi;
    int h=helperfunction(root,maxi);
    return maxi;
}

int main()
{

    return 0;
}