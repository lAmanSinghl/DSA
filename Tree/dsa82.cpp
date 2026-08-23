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

TreeNode *prevs = NULL;
void flattenApporach1(TreeNode *root)
{
    if (!root)
    {
        return;
    }
    flattenApporach1(root->right);
    flattenApporach1(root->left);
    root->right = prevs;
    root->left = NULL;
    prevs = root;
};
void flattenApporach2(TreeNode *root)
{
    stack<TreeNode *> st;
    st.push(root);
    while (!st.empty())
    {
        TreeNode *node = st.top();
        st.pop();
        if (node->left)
            st.push(node->left);
        if (node->right)
            st.push(node->right);
        if (!st.empty())
            node->right = st.top();
        node->left == NULL;
    }
}
void flattenApporach3(TreeNode *root)
{
    TreeNode *curr = root;
    while (!curr)
    {
        if (curr->left)
        {
            TreeNode *prev = curr->left;
            while (prev->right)
            {
                prev=prev->right;
            }
            prev->right=curr->right;
            curr->right=curr->left;
        }
        curr=curr->right;

    }
}
int main()
{

    return 0;
}