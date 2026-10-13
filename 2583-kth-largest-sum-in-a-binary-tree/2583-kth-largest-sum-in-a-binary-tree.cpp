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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        long long res = 0;
        priority_queue<long long>pq;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            long long temp_sum = 0;
            int size = q.size();
            for(int i = 0 ; i < size ; i++){
                TreeNode * node = q.front();
                q.pop();
                temp_sum += node->val;
                if(node->left != nullptr){
                    q.push(node->left);
                }
                if(node->right != nullptr){
                    q.push(node->right);
                }
            }
            pq.push(temp_sum);
        }
        while(k > 1 && !pq.empty()){
            pq.pop();
            k--;
        }
        res = pq.top();
        return pq.empty() ? -1 : res;
        return res;
    }
};