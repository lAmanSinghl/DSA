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
bool isValid(TreeNode * root,long long lowerRange,long long higherRange){
    if(!root){
        return true;
    }
     return (root->val>lowerRange&&root->val<higherRange)&&isValid(root->left,lowerRange,root->val)&&isValid(root->right,root->val,higherRange);

}
bool isValidBST(TreeNode *root)
{
    return isValid(root,LLONG_MIN,LLONG_MAX);
}
int main()
{

    return 0;
}