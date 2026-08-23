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
vector<int> morrisInorder(TreeNode *root)
{
    TreeNode *curr=root;
    vector <int> sol;
    while(curr!=NULL){
        if(curr->left ==NULL){
            sol.push_back(curr->val);
            curr=curr->right;
        }else{
            TreeNode *prev=curr->left;
            while(prev->right&&prev->right!=curr){
                prev=prev->right;
            }
            if(prev->right==NULL){
                prev->right=curr;
                curr=curr->left;
            }else{
                prev->right=NULL;
                sol.push_back(curr->val);
                curr=curr->right;
            }
        }
    }
    return sol;
}
vector<int> morrisPreorder(TreeNode *root)
{
    TreeNode *curr=root;
    vector <int> sol;
    while(curr!=NULL){
        if(curr->left ==NULL){
            sol.push_back(curr->val);
            curr=curr->right;
        }else{
            TreeNode *prev=curr->left;
            while(prev->right&&prev->right!=curr){
                prev=prev->right;
            }
            if(prev->right==NULL){
                prev->right=curr;
                //we only change this line to convert it from inorder to preorder
                sol.push_back(curr->val); 
                curr=curr->left;
            }else{
                prev->right=NULL;
                // sol.push_back(curr->val);
                curr=curr->right;
            }
        }
    }
    return sol;
}
int main()
{

    return 0;
}