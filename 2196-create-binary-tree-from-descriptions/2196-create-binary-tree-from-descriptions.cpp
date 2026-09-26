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
    TreeNode* createBinaryTree(vector<vector<int>>& d) {
        int n = d.size();
        unordered_map<int,int>parent_map;
        unordered_map<int,int>child_map;
        for(int i = 0 ; i < n ; i++){
            parent_map[d[i][0]] = 1;
            child_map[d[i][1]] = 1;
        }
        int parent = -1;
        for(auto i : parent_map){
            if(child_map.find(i.first) == child_map.end()){
                parent = i.first;
            }
        }
        unordered_map<int, TreeNode*> mp;

        for(int i = 0; i < n; i++) {

            int p = d[i][0];

            int c = d[i][1];

            int dir = d[i][2];

            // Create parent if doesn't exist

            if(mp.find(p) == mp.end()) {

                mp[p] = new TreeNode(p);

            }

            // Create child if doesn't exist

            if(mp.find(c) == mp.end()) {

                mp[c] = new TreeNode(c);

            }

            // Connect

            if(dir == 1) {

                mp[p]->left = mp[c];

            }

            else {

                mp[p]->right = mp[c];

            }

        }

        return mp[parent];
    }
};