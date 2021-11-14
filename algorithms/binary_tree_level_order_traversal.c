/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#define QUEUE_SIZE 2000

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    if(!root) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }
    
    // Can allocate less here and realloc if necessary to 
    // minimize memory usage
    int max_levels = QUEUE_SIZE;
    int** result = malloc(max_levels * sizeof(int*));
    *returnColumnSizes = malloc(max_levels * sizeof(int));
    int num_levels = 0;
    
    struct TreeNode* queue[QUEUE_SIZE];
    queue[0] = root;
    int back = 1;
    int front = 0;
    int size = 1;
    while(size > 0) {
        int level_size = size;
        
        result[num_levels] = malloc(level_size * sizeof(int));
        (*returnColumnSizes)[num_levels] = level_size;
        
        for(int i = 0; i < level_size; ++i) {
            struct TreeNode* current_node = queue[front];
            front = (front + 1) % QUEUE_SIZE;
            size--;
            
            result[num_levels][i] = current_node->val;
            
            if(current_node->left) {
                queue[back] = current_node->left;
                back = (back + 1) % QUEUE_SIZE;
                size++;
            }
            if(current_node->right) {
                queue[back] = current_node->right;
                back = (back + 1) % QUEUE_SIZE;
                size++;
            }
        }
        
        ++num_levels;
    }
    
    *returnSize = num_levels;
    return result;
}
