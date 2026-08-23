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

vector<TreeNode *> findPreSuc(TreeNode *root, int key)
{
    TreeNode *pre = NULL, *suc = NULL;

    while (root != NULL)
    {
        if (root->val > key)
        {
            suc = root;
            root = root->left;
        }
        else if (root->val < key)
        {
            pre = root;
            root = root->right;
        }
        else
        {
            if (root->left)
            {
                TreeNode *node = root->left;
                while (node->right)
                {
                    node = node->right;
                }
                pre = node;
            }
            if (root->right)
            {
                TreeNode *node = root->right;
                while (node->left)
                {
                    node = node->left;
                }
                suc = node;
            }
            break;
        }
    }
    return {pre, suc};
}

int main()
{

    return 0;
}