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
    vector<int>Inorder;
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        Inorder.push_back(root->val);
        inorder(root->right);
    }
    // int max_ele(vector<int>&Inorder , int start ,int end){
    //     int ind = -1;
    //     int maxi = -1e9 + 7;
    //     for(int i = start ; i <= end ; i++){
    //         if(Inorder[i] > maxi){
    //             maxi = Inorder[i];
    //             ind = i;
    //         }
    //     }
    //     return ind;
    // }
    TreeNode* buildTree(vector<int>&Inorder , int start ,int end){
        if(start > end) return nullptr;
        int mid = start + (end - start) / 2;
        TreeNode * node = new TreeNode(Inorder[mid]);
        node->left = buildTree(Inorder , start , mid - 1);
        node->right = buildTree(Inorder , mid + 1 , end);
        return node;
    }
    TreeNode* balanceBST(TreeNode* root) {
        if(!root) return nullptr;
        inorder(root);
        int n = Inorder.size() - 1;
        return buildTree(Inorder , 0 , n);
    }
};