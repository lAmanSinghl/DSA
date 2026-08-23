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
TreeNode *searchBST(TreeNode *root, int val)
{
    TreeNode *node;
    while (node->val != val)
    {
        if (node->val < val)
        {
            node = node->right;
        }
        else
        {
            node = node->left;
        }
    }
    return node;
}
vector<int> floorCeilOfBST(TreeNode *root, int key)
{
    int floor=INT_MIN,ceil=INT_MAX;
    while(root){
        if(root->val==key){
        return {key,key};
        }
        else if(root->val>key){
            ceil=root->val;
            root=root->left;
        }else{
            floor=root->val;
            root=root->right;
        }
    }
    return {floor,ceil};
}
int main()
{
    return 0;
}