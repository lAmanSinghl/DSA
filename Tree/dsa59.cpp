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

// PreOrder ROOT LEFT RIGHT
void preOrder(TreeNode *root, vector<int> &ans)
{
    if (root == NULL)
        return;
    ans.push_back(root->val);
    preOrder(root->left, ans);
    preOrder(root->right, ans);
}
vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> ans;
    preOrder(root, ans);
    return ans;
}
//---------------------------------//

// inOrder LEFT ROOT RIGHT
void inOrder(TreeNode *root, vector<int> &ans)
{
    if (root == NULL)
        return;
    inOrder(root->left, ans);
    ans.push_back(root->val);
    inOrder(root->right, ans);
}
vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> ans;
    inOrder(root, ans);
    return ans;
}
//---------------------------------------------------//
// level order one level at a time
vector<vector<int>> levelOrder(TreeNode *root)
{
    queue<TreeNode *> q;
    vector<vector<int>> ans;
    if (root == NULL)
        return ans;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        vector<int> level;
        for (int i = 0; i < size; i++)
        {
            TreeNode *node = q.front();
            q.pop();
            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);
            level.push_back(node->val);
        }
        ans.push_back(level);
    }
    return ans;
}
//----------------------------------------------------//
// Iterative preorder
vector<int> IterativePreOrder(TreeNode *root)
{
    vector<int> preOrder;
    if (root == NULL)
        return preOrder;
    stack<TreeNode *> st;
    st.push(root);
    while (!st.empty())
    {
        TreeNode *node = st.top();
        st.pop();
        preOrder.push_back(node->val);
        if (node->right != NULL)
            st.push(node->right);
        if (node->left != NULL)
            st.push(node->left);
    }
    return preOrder;
}
//---------------------------------//

// iterative inOrder LEFT ROOT RIGHT
vector<int> IterativeInOrder(TreeNode *root)
{
    vector<int> inOrder;
    stack<TreeNode *> st;
    TreeNode *node = root;
    while (true)
    {
        if (node != NULL)
        {
            st.push(node);
            node = node->left;
        }
        else
        {
            if (st.empty() == true)
                break;
            node = st.top();
            st.pop();
            inOrder.push_back(node->val);
            node = node->right;
        }
    }
    return inOrder;
}
//---------------------------------//

// iterative postOrder LEFT ROOT RIGHT
vector<int> IterativePostOrder(TreeNode *root)
{
    vector<int> postOrder;
    stack<TreeNode *> st;
    TreeNode *node = root;

    while (node != NULL || !st.empty())
    {
        if (node != NULL)
        {
            st.push(node);
            node = node->left;
        }
        else
        {
            TreeNode *temp = st.top()->right;
            if (temp == NULL)
            {
                temp = st.top();
                st.pop();
                postOrder.push_back(temp->val);
                while (!st.empty() && temp == st.top()->right)
                {
                    temp = st.top(), st.pop();
                    postOrder.push_back(temp->val);
                }
            }
            else
            {
                node = temp;
            }
        }
    }
    return postOrder;
}
// doing all three at one iterativly
vector<vector<int>> treeTraversal(TreeNode *root)
{
    vector<int> pre, in, post;
    stack<pair<TreeNode *, int>> st;
    st.push({root, 1});
    if (root == NULL)
        return;
    while (!st.empty())
    {
        auto it = st.top();
        st.pop();
        if (it.second == 1)
        {
            pre.push_back(it.first->val);
            it.second++;
            st.push(it);
            if (it.first->left != NULL)
            {
                st.push({it.first->left, 1});
            }
        }
        else if (it.second == 2)
        {
            in.push_back(it.first->val);
            it.second++;
            st.push(it);
            if (it.first->right != NULL)
            {
                st.push({it.first->right, 1});
            }
        }
        else
        {
            post.push_back(it.first->val);
        }
    }
    return {pre,in,post};
}
int main()
{

    return 0;
}