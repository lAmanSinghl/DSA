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
class BSTIterator {
    stack <TreeNode *> st;
    bool reverse=true;
public:
    BSTIterator(TreeNode* root,bool isReverse) {
        reverse=isReverse;
        pushAll(root);
    }
    
    int next() {
        TreeNode *node=st.top();
        st.pop();
        if(!reverse)pushAll(node->right);
        else pushAll(node->left);
        return node->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
private:
    void pushAll(TreeNode *root){
        while(root!=NULL){
            st.push(root);
            if(reverse){
                root=root->right;
            }else{
                root=root->left;
            }
        }
    }
};
bool findTarget(TreeNode *root, int k)
{
    if(!root)return false;
    BSTIterator l(root,0);
    BSTIterator r(root,1);

    int i=l.next();
    int j=r.next();

    while(i<j){
        if(i+j==k)return true;
        else if(i+j<k){
             i=l.next();
        }else{
            j=r.next();
        }
    }
    return false;
}
int main()
{

    return 0;
}