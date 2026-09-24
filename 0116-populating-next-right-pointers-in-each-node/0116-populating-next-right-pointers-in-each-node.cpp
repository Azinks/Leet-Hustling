/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr) return nullptr;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i = 0 ; i < size ; i++){
                Node* levelNode = q.front();
                q.pop();
                cout<<levelNode->val<<endl;

                //This Below If Won't Work As Every Non-last Node Will Fill The Queue 
                // if(q.empty()){
                //     cout<<"In"<<endl;
                //     levelNode->next = nullptr;
                // }
                if(i == size - 1){
                    cout<<"In"<<endl;
                    levelNode->next = nullptr;
                }
                else{
                    Node* levelNext = q.front();
                    levelNode->next = levelNext;
                }
                if(levelNode->left != nullptr) q.push(levelNode->left);
                if(levelNode->right != nullptr) q.push(levelNode->right);
            }
        }
        return root;
    }
};