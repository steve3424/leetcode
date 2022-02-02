/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if(!head) {
        return false;
    }
    
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    do {
        slow = slow->next;
        fast = fast->next ? fast->next->next : fast->next;
        if(slow == fast) {
            return slow && fast;
        }
    } while(slow && fast);
    
    return false;
}
