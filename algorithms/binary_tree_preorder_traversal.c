/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* preorderTraversal(struct TreeNode* root, int* returnSize){
    if(!root) {
        *returnSize = 0;
        return NULL;
    }
    
    int write_i = 0;
    int* result = malloc(100 * sizeof(int));
    
    struct TreeNode* node_stack[100];
    node_stack[0] = root;
    int top = 1;
    while(top) {
        struct TreeNode* node = node_stack[--top];
        result[write_i++] = node->val;
        
        if(node->right) {
            node_stack[top++] = node->right;
        }
        if(node->left) {
            node_stack[top++] = node->left;
        }
    }
    
    *returnSize = write_i;
    return result;
}
