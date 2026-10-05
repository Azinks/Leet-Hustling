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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }

        if (root == nullptr) return root;
        int deep = 0;
        queue<TreeNode*>q;
        q.push(root);
        bool flag = false;
        while(!q.empty()){
            deep++;
            int size = q.size();
            if(depth - 1 == deep){
                for(int i = 0 ; i < size ; i++){
                    TreeNode* node = q.front();
                    q.pop();

                    TreeNode* newLeft = new TreeNode(val);
                    newLeft->left = node->left;
                    node->left = newLeft;

                    TreeNode* newRight = new TreeNode(val);
                    newRight->right = node->right;
                    node->right = newRight;
            }
            return root;
        }
            else{
                for(int i = 0 ; i < size ; i++){
                    TreeNode * node = q.front();
                    q.pop();
                    if(node->left){
                        q.push(node->left);
                    }
                    if(node->right){
                        q.push(node->right);
                    }
                }
            }
        }
        return root;
    }

};