/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* prev_node = NULL;
    struct ListNode* delete_node = head;
    struct ListNode* end_node = head;
    
    // Move end pointer n nodes ahead
    // of delete pointer
    while(end_node && n--) {
        end_node = end_node->next;
    }
    
    // Move through list until end node
    // falls off. Now delete node should
    // be nth from end.
    while(end_node) {
        prev_node = delete_node;
        delete_node = delete_node->next;
        end_node = end_node->next;
    }
    
    // Special case for deleting head.
    if(delete_node == head) {
        head = delete_node->next;
        free(delete_node);
    }
    else {
        prev_node->next = delete_node->next;
        free(delete_node);
    }
    
    return head;
}
