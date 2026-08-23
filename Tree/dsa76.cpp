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
TreeNode* markParents(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parent_track,int target)
{
    TreeNode *targetnode=NULL;
    queue <TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        for(int i=0;i<n;i++){
            TreeNode*node=q.front();
            q.pop();
            if(node->val==target)targetnode=node;
            if(node->left){
                q.push(node->left);
                parent_track[node->left]=node;
            }if(node->right){
                q.push(node->right);
                parent_track[node->right]=node;
            }
        }
    }
    return targetnode;

}
// TreeNode *findit(TreeNode *root, int target)
// {
//     if (!root)return NULL;
//     if (root->val == target)return root;
//     TreeNode *left = findit(root->left, target);
//     if (left)return left;
//     return findit(root->right, target);
// }
int minTime(TreeNode *root, int target)
{
    
    unordered_map<TreeNode *, TreeNode *> parent_track;
    TreeNode *targetNode=markParents(root, parent_track,target);
    queue<TreeNode *> q;
    unordered_map<TreeNode *, bool> visited;
    q.push(targetNode);
    visited[targetNode] = true;
    int j = 0;
    while (!q.empty())
    {
        int n = q.size();
        j++;
        for (int i = 0; i < n; i++)
        {
            TreeNode *node = q.front();
            q.pop();
            if (node->left && !visited[node->left])
            {
                q.push(node->left);
                visited[node->left] = true;
            }
            if (node->right && !visited[node->right])
            {
                q.push(node->right);
                visited[node->right] = true;
            }
            if (parent_track[node] && !visited[parent_track[node]])
            {
                q.push(parent_track[node]);
                visited[parent_track[node]] = true;
            }
        }
    }
    return j-1;
}
int main()
{

    return 0;
}