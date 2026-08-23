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

void markParents(TreeNode * root,unordered_map<TreeNode*,TreeNode*>&parent_track){
    if(root==NULL)return;
    if(root->left)parent_track[root->left]=root;
    if(root->right)parent_track[root->right]=root;
    markParents(root->left,parent_track);
    markParents(root->right,parent_track);
}
vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
{
    unordered_map<TreeNode*,TreeNode*>parent_track;
    markParents(root,parent_track);
    unordered_map<TreeNode*,bool>visited;
    queue<TreeNode*>q;
    q.push(target);
    visited[target]=true;
    int curr_lvl=0;
    while(!q.empty()){
        int n=q.size();
        if(curr_lvl++==k)break;
        for(int i=0;i<n;i++){
            TreeNode* node=q.front();
            q.pop();
            if(node->left && !visited[node->left]){
                q.push(node->left);
                visited[node->left]=true;
            }if(node->right && !visited[node->right]){
                q.push(node->right);
                visited[node->right]=true;
            }if(parent_track[node]&&!visited[parent_track[node]]){
                q.push(parent_track[node]);
                visited[parent_track[node]]=true;
            }
        }

    }
    vector<int>result;
    while(!q.empty()){
        result.push_back(q.front()->val);
        q.pop();

    }
    return result;

}

int main()
{

    return 0;
}