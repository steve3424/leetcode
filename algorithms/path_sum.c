/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct {
    struct TreeNode* node;
    int previous_sum;
} NodeSum;

bool hasPathSum(struct TreeNode* root, int targetSum){
    if(root == NULL) {
        return false;
    }
    
    NodeSum node_stack[5000];
    NodeSum root_ns;
    root_ns.node = root;
    root_ns.previous_sum = 0;
    node_stack[0] = root_ns;
    int top = 1;
    while(top) {
        NodeSum node_sum = node_stack[--top]; 
        int current_sum = node_sum.previous_sum + node_sum.node->val;
        
        bool has_right_child = node_sum.node->right != NULL;
        bool has_left_child = node_sum.node->left != NULL;
        if((current_sum == targetSum) &&
           (!has_right_child) &&
           (!has_left_child)) 
        {
            return true;
        }
        else {
            if(has_right_child) {
                NodeSum ns;
                ns.node = node_sum.node->right;
                ns.previous_sum = current_sum;
                node_stack[top++] = ns;
            }
            if(has_left_child) {
                NodeSum ns;
                ns.node = node_sum.node->left;
                ns.previous_sum = current_sum;
                node_stack[top++] = ns;
            }
        }
    }
    
    return false;
}
