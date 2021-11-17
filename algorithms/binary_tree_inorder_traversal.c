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


int* inorderTraversal(struct TreeNode* root, int* returnSize){
    if(!root) {
        *returnSize = 0;
        return NULL;
    }
    
    int res_push = 0;
    int* result = malloc(200 * sizeof(int));
    if(!result) {
        printf("couldn't malloc for res...\n");
        return NULL;
    }
    
    struct TreeNode* stack[200];
    int push = 0;
    stack[push++] = root;
    struct TreeNode* push_left = root;
    while(push > 0) {
        // push all nodes along left of tree
        while(push_left) {
            if(push_left->left) {
                stack[push++] = push_left->left;
            }
            push_left = push_left->left;
        }
        
        struct TreeNode* current_node = stack[--push];
        result[res_push++] = current_node->val;
        
        if(current_node->right) {
            stack[push++] = current_node->right;
            push_left = current_node->right;
        }
    }
    
    *returnSize = res_push;
    return result;
}
