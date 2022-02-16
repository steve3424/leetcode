/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode* p1 = headA;
    struct ListNode* p2 = headB;
    
    while(p1 != p2){
        p1 = p1 == NULL ? headB : p1->next;
        p2 = p2 == NULL ? headA : p2->next;
    }
        
    return p1;
    
    // Get len of both lists
    //int a_len = 0;
    //int b_len = 0;
    //
    //struct ListNode* a = headA;
    //struct ListNode* b = headB;
    //while(a) {
    //    a_len++;
    //    a = a->next;
    //}
    //while(b) {
    //    b_len++;
    //    b = b->next;
    //}
    //
    //// move the longer list ahead by diff
    //a = headA;
    //b = headB;
    //if(a_len > b_len) {
    //    int len_diff = a_len - b_len;
    //    for(int i = 0; i < len_diff; ++i) {
    //        a = a->next;
    //    }
    //}
    //else {
    //    int len_diff = b_len - a_len;
    //    for(int i = 0; i < len_diff; ++i) {
    //        b = b->next;
    //    }
    //}
    //
    //// go until we find the common pointer
    //while(a != b) {
    //    a = a->next;
    //    b = b->next;
    //}
    //
    //return a;
}
