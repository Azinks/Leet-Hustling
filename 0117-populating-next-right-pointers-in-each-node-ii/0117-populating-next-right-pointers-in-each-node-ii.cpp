class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) return nullptr;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            Node* prev = nullptr;

            for (int i = 0; i < size; i++) {
                Node* currNode = q.front();
                q.pop();

                if (prev != nullptr) {
                    prev->next = currNode;
                }
                prev = currNode;
                // if(!q.empty()){
                //     currNode->next = q.front();
                // }

                if (currNode->left != nullptr) {
                    q.push(currNode->left);
                }
                if (currNode->right != nullptr) {
                    q.push(currNode->right);
                }
            }

            prev->next = nullptr;
        }

        return root;
    }
};