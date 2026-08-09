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
vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> ans;
    if(root==NULL)return ans;
    queue <TreeNode *> q;
    q.push(root);
    int flag=1;
    while (!q.empty())
    {
        int n=q.size();
        flag=1-flag;;
        vector<int> level(n);
        for(int i=0;i<n;i++){
            TreeNode * node=q.front();
            q.pop();
            if(node->left!=NULL)q.push(node->left);
            if(node->right!=NULL)q.push(node->right);
            int index=flag?i:n-1-i;
            level[index]=(node->val);
        }
        ans.push_back(level);
        
    }
    
    return ans;
}

int main()
{

    return 0;
}