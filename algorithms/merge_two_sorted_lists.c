/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    // catch cases where l1, l2, or both lists are empty
    if(!l1) {
        return l2;
    }
    if(!l2) {
        return l1;
    }
    
    struct ListNode* ret;
    struct ListNode* prev;
    if(l1->val <= l2->val) {
        ret = l1;
        prev = l1;
        l1 = l1->next;
    }
    else {
        ret = l2;
        prev = l2;
        l2 = l2->next;
    }
    
    while(l1 && l2) {
       if(l1->val <= l2->val) {
           prev->next = l1;
           prev = l1;
           l1 = l1->next;
       } 
       else {
           prev->next = l2;
           prev = l2;
           l2 = l2->next;
       }
    }
    prev->next = l1 ? l1 : l2;
    return ret;
}
