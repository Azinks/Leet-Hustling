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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            double temp = 0.0;
            for(int i = 0 ; i < size ; i++){
                TreeNode * value = q.front();
                q.pop();
                if(value->left!=nullptr) q.push(value->left);
                if(value->right!=nullptr) q.push(value->right);
                temp = temp + value->val;
            }
            temp = (temp/size);
            cout<<temp<<endl;
            ans.push_back(temp);
        }

        return ans;
    }
};