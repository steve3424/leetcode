/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool NodesAreEqual(struct TreeNode* n1, struct TreeNode* n2) {
    if(!n1 && !n2) {
        return true;
    }
    else {
        if(!n1 || !n2) {
            return false;
        }
        else {
            return n1->val == n2->val;
        }
    }
}

bool SubTreesSymmetric(struct TreeNode* left_node,
                       struct TreeNode* right_node) 
{
    if(!left_node && !right_node) {
        return true;
    }
    else if(!left_node || !right_node) {
        return false;
    }
    else {
        bool vals_equal = left_node->val == right_node->val;
        bool outer_trees_symmetric = SubTreesSymmetric(left_node->left, right_node->right);
        bool inner_trees_symmetric = SubTreesSymmetric(left_node->right, right_node->left);
        return vals_equal &&
               outer_trees_symmetric &&
               inner_trees_symmetric;
    }
}

bool isSymmetric(struct TreeNode* root){
    // RECURSIVE
    if(!root) {
        return false;
    }
    
    return SubTreesSymmetric(root->left, root->right);
    
    // ITERATIVE
    //if(!root) {
    //    return false;
    //}
    
    //if(!NodesAreEqual(root->left, root->right)) {
    //    return false;
    //}
    //else {
    //    if(!root->left) {
    //        return true;
    //    }
    //}
    //
    //struct TreeNode* left_stack[1000];
    //struct TreeNode* right_stack[1000];
    //left_stack[0] = root->left;
    //right_stack[0] = root->right;
    //int left_top = 1;
    //int right_top = 1;
    //while(left_top) {
    //    --left_top;
    //    --right_top;
    //    struct TreeNode* left_node = left_stack[left_top];
    //    struct TreeNode* right_node = right_stack[right_top];
    //    
    //    struct TreeNode* left_left   = left_node->left;
    //    struct TreeNode* left_right  = left_node->right;
    //    struct TreeNode* right_left  = right_node->left;
    //    struct TreeNode* right_right = right_node->right;
    //    
    //    if(!NodesAreEqual(left_left, right_right)) {
    //        return false;
    //    }
    //    if(!NodesAreEqual(left_right, right_left)) {
    //        return false;
    //    }
    //    
    //    if(left_right) {
    //        left_stack[left_top++] = left_right;
    //    }
    //    if(left_left) {
    //        left_stack[left_top++] = left_left;
    //    }
    //    if(right_left) {
    //        right_stack[right_top++] = right_left;
    //    }
    //    if(right_right) {
    //        right_stack[right_top++] = right_right;
    //    }
    //}
    //
    //return true;
}
