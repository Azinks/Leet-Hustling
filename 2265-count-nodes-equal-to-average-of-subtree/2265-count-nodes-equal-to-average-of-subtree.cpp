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
    pair<int,int> dfs(TreeNode* root,int &avg_sum){
        if(!root){
            return {};
        }
        //check for leaf node
        if(root->left == nullptr && root->right == nullptr){
            avg_sum++;
            return {root->val,1};
        }
        int sum = 0;
        int n = 1;
        sum += root->val;
        pair<int,int> left_node = dfs(root->left,avg_sum);
        sum += left_node.first;
        n += left_node.second;
        pair<int,int> right_node = dfs(root->right,avg_sum);
        sum += right_node.first;
        n += right_node.second;
        int avg = sum / n;
        if(avg == root->val){
            avg_sum++;
        }
        return {sum,n};
    }
    int averageOfSubtree(TreeNode* root) {
        int avg_sum = 0;
        cout<<dfs(root,avg_sum).first;
        return avg_sum;
    }
};