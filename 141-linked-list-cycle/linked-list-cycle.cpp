/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    
    bool hasCycle(ListNode* head) {
        
        unordered_set<ListNode*> visitedNodes;

    
        ListNode* current = head;
        while (current != nullptr) {
            if (visitedNodes.count(current) > 0) {
                return true;
            }
            visitedNodes.insert(current);
            current = current->next;
        }
        return false;
    }
};