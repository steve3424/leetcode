/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeElements(struct ListNode* head, int val){
    // head->val == val is a special case since we want
    // to replace the head variable and return that so
    // we deal with all head deletions up front.
    while(head && head->val == val) {
        struct ListNode* new_head = head->next;
        free(head);
        head = new_head;
    }
    
    // We can start checking from head->next since
    // we did all head deletions already.
    struct ListNode* prev = head;
    struct ListNode* curr = head ? head->next : NULL;
    while(curr) {
        if(curr->val == val) {
            prev->next = curr->next;
            free(curr);
            curr = prev->next;
        }
        else {
            prev = curr;
            curr = curr->next;
        }
    }
    
    return head;
}
