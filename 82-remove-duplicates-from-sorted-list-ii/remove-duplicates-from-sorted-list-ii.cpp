class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;

        ListNode* prev = nullptr;   // Last node before current block
        ListNode* curr = head;       // Current node to examine

        while (curr) {
            if (curr->next && curr->val == curr->next->val) {
                // Found duplicates: skip the entire block
                ListNode* temp = curr; // Start of duplicates
                while (temp->next && temp->val == temp->next->val) {
                    temp = temp->next;
                }
                // temp now points to the last duplicate node
                if (prev) {
                    prev->next = temp->next; // Connect prev to node after duplicates
                } else {
                    head = temp->next;        // Update head if duplicates at beginning
                }
                curr = temp->next; // Move curr to the node after duplicates
            } else {
                // No duplicate: move both pointers forward
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};