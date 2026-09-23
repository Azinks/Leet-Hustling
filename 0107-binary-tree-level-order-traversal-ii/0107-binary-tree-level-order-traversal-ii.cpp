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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>ans;
        // ans.push_back({1,2});
        // ans.push_back({3,4});
        queue<TreeNode*>q;
        if(root == nullptr) return ans;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int>temp;
            for(int i = 0 ; i < size ; i++){
                TreeNode * value = q.front();
                q.pop();
                if(value->left != nullptr) q.push(value->left);
                if(value->right != nullptr) q.push(value->right);
                temp.push_back(value->val);
            }
            ans.push_back(temp);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};