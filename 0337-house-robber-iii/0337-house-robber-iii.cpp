/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    pair<int,int> dfs(TreeNode* root){
        if(!root){
            return {0,0};
        }
        //left child called recursively 
        pair<int,int> leftChild = dfs(root->left);
        //right child called recursively 
        pair<int,int> rightChild = dfs(root->right);

        int robbed = root->val + leftChild.first + rightChild.first;
        int notRobbed = max(leftChild.first,leftChild.second) + max(rightChild.first,rightChild.second);
        return {notRobbed,robbed};
    }
    int rob(TreeNode* root) {
        pair<int,int> ans = dfs(root);
        return max(ans.first,ans.second);
    }
};