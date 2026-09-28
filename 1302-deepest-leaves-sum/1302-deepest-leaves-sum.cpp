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
    int heightBT(TreeNode* root){
        if(root == nullptr) return 0;
        int l = heightBT(root->left);
        int r = heightBT(root->right);
        return 1 + max(l,r);
    }
    int deepestLeavesSum(TreeNode* root) {
        int height = heightBT(root);
        queue<TreeNode*>q;
        q.push(root);
        int sum = 0;
        int cnt = 0;
        while(!q.empty()){
            int size = q.size();
            cnt++;
            for(int i = 0 ; i < size ; i++){
                TreeNode * node = q.front();
                q.pop();
                if(cnt == height) sum += node->val;
                if(node->left!=nullptr) q.push(node->left);
                if(node->right!=nullptr) q.push(node->right);
            }
        }
        return sum;
    }
};