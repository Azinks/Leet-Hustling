/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    ListNode* middleNode(ListNode* head, ListNode* tail) {
        if (!head) return nullptr;
        
        ListNode* fast = head;
        ListNode* slow = head;
        
        // This avoids dereferencing a null pointer.
        while (fast != tail && fast->next != tail) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    TreeNode* buildBST(ListNode* head, ListNode* tail) {
        // Base case: If the range is empty, return nullptr
        if (head == tail) return nullptr;
        if (!head) return nullptr;
        
        // Retrieve Middle Node Of List From [head, tail)
        ListNode* middle = middleNode(head, tail);
        
        TreeNode* root = new TreeNode(middle->val);
        
        // Recursively build left and right subtrees
        root->left = buildBST(head, middle);
        root->right = buildBST(middle->next, tail);

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        // Handle base cases safely
        if (!head) return nullptr;
        if (!head->next) return new TreeNode(head->val);
        
        // FIX 2: Simply pass nullptr as the tail. 
        // In exclusive bound logic, the end of the list is represented by nullptr.
        return buildBST(head, nullptr);
    }
};
