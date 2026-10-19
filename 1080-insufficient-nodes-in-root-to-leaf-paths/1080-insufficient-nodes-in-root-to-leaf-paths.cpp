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
    TreeNode* solve(TreeNode* root, int limit , int path_sum){
        if(!root){
            return nullptr;
        }
        if(path_sum + root->val < limit && root->left == nullptr && root->right == nullptr){
            return nullptr;
        }
        if(path_sum + root->val >= limit && root->left == nullptr && root->right == nullptr){
            return root;
        }
        int curr_sum = path_sum + root->val;
        if(solve(root->left,limit,curr_sum) == nullptr){
            root->left = nullptr;
        }
        if(solve(root->right,limit,curr_sum) == nullptr){
            root->right = nullptr;
        }
        if(root->left == nullptr && root->right == nullptr){
            return nullptr;
        }
        return root;
        
    }
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        if(root->left == nullptr && root->right == nullptr && root->val < limit) return nullptr;
        
        return solve(root,limit,0);
    }
};