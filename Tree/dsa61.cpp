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

int helperFunction(TreeNode *root)
{
    // works similar to find height fucntion
    if (root == NULL)
        return 0;
    int lsth = helperFunction(root->left);
    int rsth = helperFunction(root->right);
    if (lsth == -1 || rsth == -1)
        return -1;
    if (abs(lsth - rsth) > 1)
        return -1;
    return 1 + max(lsth, rsth);
}
bool isBalanced(TreeNode *root)
{
    int h=helperFunction(root);
    if(h!=-1)return 1;
    return 0;
}
int main()
{
    
    return 0;
}