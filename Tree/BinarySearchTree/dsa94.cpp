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

class Nodevalue{
public:
    int maxNode,minNode,sum;

    Nodevalue(int maxNode,int minNode,int sum){
        this->maxNode=maxNode;
        this->minNode=minNode;
        this->sum=sum;
    }
};

class Solution {
private:
     int ans = 0;
     Nodevalue largestBSTSubtreeHelper(TreeNode *root){
        if(!root){
            return Nodevalue(INT_MIN,INT_MAX,0);
        }
        auto left=largestBSTSubtreeHelper(root->left);
        auto right=largestBSTSubtreeHelper(root->right);

        if(left.maxNode<root->val&&root->val<right.minNode){
            int sum = left.sum + right.sum + root->val;

            // Even if sum is negative, ans remains >= 0
            ans = max(ans, sum);
            return Nodevalue(max(root->val,right.maxNode),min(root->val,left.minNode),left.sum+right.sum+root->val);
        }
        return Nodevalue(INT_MAX,INT_MIN,max(left.sum,right.sum));
     }
public:
    int maxSumBST(TreeNode* root) {
        largestBSTSubtreeHelper(root);
        return ans;
    }
};

int main()
{

    return 0;
}