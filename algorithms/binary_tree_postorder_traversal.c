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
int* postorderTraversal(struct TreeNode* root, int* returnSize){
    if(!root) {
        *returnSize = 0;
        return NULL;
    }
    
    // Pre-order, left first
    int write_i = 0;
    int* result = malloc(100 * sizeof(int));
    
    struct TreeNode* node_stack[100];
    node_stack[0] = root;
    int top = 1;
    while(top) {
        struct TreeNode* node = node_stack[--top];
        result[write_i++] = node->val;
        
        if(node->left) {
            node_stack[top++] = node->left;
        }
        if(node->right) {
            node_stack[top++] = node->right;
        }
    }
    
    // Reverse the result array
    int front = 0;
    int back = write_i - 1;
    while(front < back) {
        int temp = result[front];
        result[front++] = result[back];
        result[back--] = temp;
    }
    
    *returnSize = write_i;
    return result;
}
