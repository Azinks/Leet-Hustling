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
    int sum = 0;
    void dfs(TreeNode* root , int cnt){
        if(root == nullptr) return ;
        cnt = (cnt * 10) + root->val;
        //leaf node
        if(root->left == nullptr && root->right == nullptr){
            sum += cnt;
            return ;
        }
        dfs(root->left,cnt);
        dfs(root->right,cnt);
    }
    int sumNumbers(TreeNode* root) {
        int cnt = 0;
        dfs(root,cnt);
        return sum;
    }
};