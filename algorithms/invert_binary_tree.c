/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* invertTree(struct TreeNode* root){
    if(!root) {
        return NULL;
    }
    
    struct TreeNode* node_stack[100];
    node_stack[0] = root;
    int top = 1;
    while(top) {
        struct TreeNode* node = node_stack[--top];
        
        // swap children
        struct TreeNode* temp = node->right;
        node->right = node->left;
        node->left = temp;
        
        if(node->left) {
            node_stack[top++] = node->left;
        }
        if(node->right) {
            node_stack[top++] = node->right;
        }
    }
    
    return root;
}c
