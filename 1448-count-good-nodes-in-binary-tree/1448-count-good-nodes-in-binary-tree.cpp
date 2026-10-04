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
    void solve(TreeNode * root , int &cnt , int prev_val){
        if(!root) return;
        if(root->val >= prev_val){
            cnt++;
        }
        solve(root->left,cnt,max(root->val,prev_val));
        solve(root->right,cnt,max(root->val,prev_val));
    }
    int goodNodes(TreeNode* root) {
        int cnt = 0;
        int maxi = -1e9;
        queue<pair<TreeNode*,int>>q;
        q.push({root,root->val});
        while(!q.empty()){
            int size = q.size();
            for(int i = 0 ; i < size ; i++){
                TreeNode * node =  q.front().first;
                int prev_val = q.front().second;
                q.pop();
                if(node->val >= prev_val){
                    cout<<node->val<<endl;
                    // maxi = max(maxi,max(node->val,val));
                    cnt++;

                }
                int val = max(node->val,prev_val);
                if(node->left != nullptr){
                    q.push({node->left,val});
                }
                if(node->right != nullptr){
                    q.push({node->right,val});
                }
            }
        }
        return cnt;
        // int cnt = 0;
        // solve(root,cnt,-1e9);
        // return cnt;
    }
};