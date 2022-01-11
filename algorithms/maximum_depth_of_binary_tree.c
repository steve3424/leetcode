/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int Max(int v1, int v2) {
    return (v1 > v2) ? v1 : v2;
}

int FindDepth(struct TreeNode* node) {
    if(!node) {
        return 0;
    }
    else {
        int left_depth = FindDepth(node->left);
        int right_depth = FindDepth(node->right);
        return 1 + Max(left_depth, right_depth);
    }
}

int maxDepth(struct TreeNode* root){
    int max_depth = FindDepth(root);
    return max_depth;
    
    //int depth_stack[10000] = {0};
    //struct TreeNode* node_stack[10000] = {0};
    //depth_stack[0] = 1;
    //node_stack[0] = root;
    //int top = 1;
    //int max_depth = 1;
    //while(top) {
    //    top--;
    //    struct TreeNode* node = node_stack[top];
    //    int depth = depth_stack[top];
    //    
    //    if(node->left) {
    //        depth_stack[top] = depth + 1;
    //        node_stack[top] = node->left;
    //        top++;
    //    }
    //    if(node->right) {
    //        depth_stack[top] = depth + 1;
    //        node_stack[top] = node->right;
    //        top++;
    //    }
    //    
    //    if(max_depth < depth) {
    //        max_depth = depth;
    //    }
    //}
    
    return max_depth;
}
