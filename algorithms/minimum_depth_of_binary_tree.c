/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define MAX_NODES 50

int minDepth(struct TreeNode* root){
    if(!root) {
        return 0;
    }
    
    int depth_stack[MAX_NODES];
    struct TreeNode* stack[MAX_NODES];
    stack[0] = root;
    depth_stack[0] = 1;
    int top = 1;
    int min_depth = INT_MAX;
    while(top) {
        --top;
        struct TreeNode* node = stack[top];
        int depth = depth_stack[top];
        
        if(!node->left && !node->right) {
            if(depth < min_depth) {
                min_depth = depth;
            }
        }
        else {
            if(node->left) {
                stack[top] = node->left;
                depth_stack[top] = depth + 1;
                ++top;
            }
            if(node->right) {
                stack[top] = node->right;
                depth_stack[top] = depth + 1;
                ++top;
            }
        }
    }
    
    return min_depth;
}
