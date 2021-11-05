/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* begin = NULL;
    struct ListNode* current = NULL;
    int carry = 0;
    while(l1 && l2) {
        if(!begin) {
            begin = calloc(1, sizeof(struct ListNode));
            current = begin;
        }
        else {
            current->next = calloc(1, sizeof(struct ListNode));
            current = current->next;
        }
            
        int res = l1->val + l2->val + carry;
        int val = res % 10;
        carry = res / 10;
        
        current->val = val;
        
        l1 = l1->next;
        l2 = l2->next;
    }
    
    while(l1) {
        current->next = calloc(1, sizeof(struct ListNode));
        current = current->next;
        
        int res = l1->val + carry;
        int val = res % 10;
        carry = res / 10;
        
        current->val = val;
        l1 = l1->next;
    }
    
    while(l2) {
        current->next = calloc(1, sizeof(struct ListNode));
        current = current->next;
        
        int res = l2->val + carry;
        int val = res % 10;
        carry = res / 10;
        
        current->val = val;
        l2 = l2->next;
    }
    
    if(carry > 0) {
        current->next = calloc(1, sizeof(struct ListNode));
        current = current->next;
        current->val = carry;
    }
    
    return begin;
}
