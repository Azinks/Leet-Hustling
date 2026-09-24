class Solution {
public:
    bool solve(TreeNode* root, int targetSum) {
        if (root == nullptr)
            return false;

        // If leaf node
        if (root->left == nullptr && root->right == nullptr) {
            return targetSum == root->val;
        }

        targetSum -= root->val;

        return solve(root->left, targetSum) ||
               solve(root->right, targetSum);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        return solve(root, targetSum);
    }
};