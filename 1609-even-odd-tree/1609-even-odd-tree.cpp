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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*>q;
        if(root->val % 2 == 0){
            return false;
        }
        if(root->left!=nullptr){
            q.push(root->left);
        }
        if(root->right!=nullptr){
            q.push(root->right);
        }
        int level = 0;
        while(!q.empty()){
            level++;
            int size = q.size();
            int prev = -1;
            for(int i = 0 ; i < size ; i++){
                if(level % 2 == 0){
                    //even level
                    TreeNode * even_level_odd_node = q.front();
                    q.pop();
                    int val = even_level_odd_node->val;
                    if(val % 2 == 0){
                        cout<<level<<" "<<val<<endl;
                        return false;
                    }
                    if(prev == -1 || prev < val){
                        prev = val;
                    }
                    else{
                        cout<<level<<" "<<val<<endl;
                        return false;
                    }
                    if(even_level_odd_node->left != nullptr){
                        q.push(even_level_odd_node->left);
                    }
                    if(even_level_odd_node->right != nullptr){
                        q.push(even_level_odd_node->right);
                    }
                }
                else{
                    //oddlevel
                    TreeNode * odd_level_even_node = q.front();
                    q.pop();
                    int val = odd_level_even_node->val;
                    if(val % 2 != 0){
                        cout<<level<<" "<<val<<endl;
                        return false;
                    }
                    if(prev == -1 || prev > val){
                        prev = val;
                    }
                    else{
                        cout<<level<<" "<<val<<endl;
                        return false;
                    }
                    if(odd_level_even_node->left != nullptr){
                        q.push(odd_level_even_node->left);
                    }
                    if(odd_level_even_node->right != nullptr){
                        q.push(odd_level_even_node->right);
                    }
                }
            }
        }
        return true;
    }
};