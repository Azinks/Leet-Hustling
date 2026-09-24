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
    int solve(TreeNode* root,int &result){
        if(root == nullptr) return 0;
        int left = solve(root->left,result);
        int right = solve(root->right,result);
        int temp = max(max(left,right) + root->val,root->val);
        int ans = max(temp , left+right+root->val);
        result = max(result , ans);
        return temp;
    }
    int maxPathSum(TreeNode* root) {
        int result = -2000;
        solve(root,result);
        return result;
    }
};