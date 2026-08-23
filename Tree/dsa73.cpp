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

int widthOfBinaryTree(TreeNode *root)
{
    queue <pair<TreeNode *,int>>q;
    int maxwidth=INT_MIN;
    q.push({root,0});
    while(!q.empty()){
        int n=q.size();
        int min=q.front().second;
        int first,last;
        for(int i=0;i<n;i++){
            int curr_id=q.front().second-min;
            auto node=q.front().first;
            q.pop();
            if(i==0)first=curr_id;
            if(i==n-1)last=curr_id;
            if(node->left)q.push({node->left,curr_id*2+1});
            if(node->right)q.push({node->right,curr_id*2+2});
        }
        maxwidth=max(maxwidth,last-first+1);
    }
    return maxwidth;
}

int main()
{

    return 0;
}