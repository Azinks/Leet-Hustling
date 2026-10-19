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
    int maxLevelSum(TreeNode* root) {
        int res = INT_MIN;
        queue<TreeNode*>q;
        q.push(root);
        int level = 0;
        int res_res = 0;
        while(!q.empty()){
            level++;
            int sum = 0;
            int size = q.size();
            for(int i = 0 ; i < size ; i++){
                TreeNode * node = q.front();
                q.pop();
                sum += node->val;
                if(node->left != nullptr){
                    q.push(node->left);
                }
                if(node->right != nullptr){
                    q.push(node->right);
                }
            }
            cout<<sum<<" "<<level<<endl;
            if(sum > res){
                res = sum;
                res_res = level;
            }
        }
        return res_res;
    }
};