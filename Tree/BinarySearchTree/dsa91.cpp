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
public:
    stack <TreeNode *> st;
    BSTIterator(TreeNode* root) {
        while(root){
            st.push(root);
            root=root->left;
        }
    }
    
    int next() {
        TreeNode *node=st.top();
        int value=node->val;
        st.pop();
        if(node->right){
            node=node->right;
            while(node){
                st.push(node);
                node=node->left;
            }
        }
        return value;

    }
    
    bool hasNext() {
        return !st.empty();
    }
};
int main()
{
    
    return 0;
}