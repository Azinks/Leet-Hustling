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
    vector<int>solve(TreeNode* root, int &distance , int &goodPairs){
        if(root == NULL){
            return {0};
        }
        if(root->left == nullptr && root->right == nullptr){
            return {1};
        }
        vector<int>left_d = solve(root->left , distance , goodPairs);
        vector<int>right_d = solve(root->right , distance , goodPairs);

        // calculate goodPairs Till Now 
        for(int i = 0 ; i < left_d.size() ; i++){
            for(int j = 0 ; j < right_d.size() ; j++){
                if(left_d[i] != 0 && right_d[j] != 0 && left_d[i] + right_d[j] <= distance){
                    goodPairs++;
                }
            }
        }

        // return new values to the parent
        vector<int>curr_d;
        for(int &i : left_d){
            if(i!=0 && i + 1 <= distance){
                curr_d.push_back(i + 1);
            }
        }
        for(int &j : right_d){
            if(j!=0 && j + 1 <= distance){
                curr_d.push_back(j + 1);
            }
        }
        return curr_d;
    }
    int countPairs(TreeNode* root, int distance) {
        int goodPairs = 0;
        solve(root , distance , goodPairs);
        return goodPairs;
    }
};