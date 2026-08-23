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
bool findpath(TreeNode *root, int x, vector<int> &arr)
{
    if (!root)
        return false;
    arr.push_back(root->val);
    if (root->val == x)
        return true;
    if (findpath(root->left, x, arr) || findpath(root->right, x, arr))
        return true;
    arr.pop_back();
    return false;
}
vector<int> solution(TreeNode *root, int x)
{
    vector<int> arr;
    if (root == NULL)
        return arr;
    findpath(root, x, arr);
    return arr;
}
void findleafpaths(TreeNode *root, vector<vector<int>> &arr, vector<int> &path)
{
    if (!root)
        return;
    path.push_back(root->val);
    findleafpaths(root->left, arr, path);
    findleafpaths(root->right, arr, path);
    if (root->left == NULL && root->right == NULL)
    {
        arr.push_back(path);
    }
    path.pop_back();
}
vector<vector<int>> paths(TreeNode *root)
{
    vector<vector<int>> arr;
    vector<int> path;
    if (root == NULL)
        return arr;
    findleafpaths(root, arr, path);
    return arr;
}
int main()
{

    return 0;
}