class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;

        ListNode* prev = nullptr;  
        ListNode* curr = head;     

        while (curr) {
            if (curr->next && curr->val == curr->next->val) {
                
                ListNode* temp = curr; // Start of duplicates
                while (temp->next && temp->val == temp->next->val) {
                    temp = temp->next;
                }
                if (prev) {
                    prev->next = temp->next; 
                } else {
                    head = temp->next;        
                }
                curr = temp->next; 
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};