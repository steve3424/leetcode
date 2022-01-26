/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    if(!p || !q) {
        return !p && !q;
    }
    
    struct TreeNode* p_stack[100] = {0};
    struct TreeNode* q_stack[100] = {0};
    int p_push = 0;
    int q_push = 0;
    p_stack[p_push++] = p;
    q_stack[q_push++] = q;
    while(p_push > 0 && q_push > 0) {
        struct TreeNode* p_node = p_stack[--p_push];
        struct TreeNode* q_node = q_stack[--q_push];
        
        // check values match
        if(p_node->val != q_node->val) {
            return false;
        }
        
        // check structure matches
        if(p_node->right || q_node->right) {
            if(p_node->right && q_node->right) {
                p_stack[p_push++] = p_node->right;
                q_stack[q_push++] = q_node->right;
            }
            else {
                return false;
            }
        }
        if(p_node->left || q_node->left) {
            if(p_node->left && q_node->left) {
                p_stack[p_push++] = p_node->left;
                q_stack[q_push++] = q_node->left;
            }
            else {
                return false;
            }
        }
    }
    return true;
}
