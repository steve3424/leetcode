/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteDuplicates(struct ListNode* head){
    if(!head) {
        return NULL;
    }
    
    struct ListNode* current = head;
    struct ListNode* next = head->next;
    while(next) {
        if(current->val == next->val) {
            current->next = next->next;
            free(next);
            next = current->next;
        }
        else {
            current = next;
            next = current->next;
        }
    }
    
    return head;
}
