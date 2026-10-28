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
    int maxEle(vector<int>& nums , int i , int j){
        int index = -1;
        int maxi = -1;
        for(int k = i ; k <= j ; k++){
            if(nums[k] > maxi){
                maxi = nums[k];
                index = k;
            }
        }
        return index;
    }
    TreeNode* buildBT(vector<int>& nums , int i , int j){
        if(i > j) return NULL;
        //calculate maximum ele in the range i, j
        int ind = maxEle(nums,i,j);
        TreeNode * node = new TreeNode(nums[ind]);
        //assign element to right and left
        node->left = buildBT(nums , i , ind - 1);
        node->right = buildBT(nums , ind + 1 , j);
        return node;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return buildBT(nums , 0 , nums.size() - 1);
    }
};