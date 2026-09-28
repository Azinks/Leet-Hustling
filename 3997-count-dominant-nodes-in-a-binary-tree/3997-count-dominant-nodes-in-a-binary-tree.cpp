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
     int fn( TreeNode* root ,int &count ) {

        // base case
        if ( root == nullptr ) return INT_MIN ;

        int left = fn( root->left , count ) ;
        int right = fn( root->right , count ) ;

        if ( root->val >= left && root->val >= right ) count++ ;

        return max( {left , right , root->val} ) ;

    }

    int countDominantNodes(TreeNode* root) {

        int count = 0 ;

        fn( root , count ) ;

        return count ;
        
    }
};