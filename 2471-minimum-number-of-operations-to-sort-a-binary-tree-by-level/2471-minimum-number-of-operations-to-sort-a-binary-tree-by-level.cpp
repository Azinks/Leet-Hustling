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
    int minSwap(vector<int>&arr){
        map<int,int>mpp;
        for(int i = 0 ; i < arr.size() ; i++) mpp[arr[i]] = i;
        int ind = 0 ;
        int ans = 0 ;
        for(auto it : mpp){
            cout<<it.second<<" "<<endl;
            if(it.second == ind) {ind++; continue;}
            mpp[arr[ind]] = it.second;
            swap(arr[ind],arr[it.second]);
            ans++;ind++; 
        }
        return ans;
    }
    int minimumOperations(TreeNode* root) {
        int opt = 0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int>arr;
            for(int i = 0 ; i < size ; i++){
                TreeNode* node = q.front();
                q.pop();
                arr.push_back(node->val);
                if(node->left!=nullptr) q.push(node->left);
                if(node->right!=nullptr) q.push(node->right);
            }
            opt += minSwap(arr);
        }
        return opt;
    }
};