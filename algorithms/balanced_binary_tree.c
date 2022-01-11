/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int Max(int n1, int n2) {
    return n1 > n2 ? n1 : n2;
}

int GetHeight(struct TreeNode* node, bool* is_balanced) {
    if(!node) {
        return -1;
    }
    else {
        int left_height = GetHeight(node->left, is_balanced);
        int right_height = GetHeight(node->right, is_balanced);
        if((left_height - right_height)  > 1 ||
           (left_height - right_height) < -1) 
        {
            *is_balanced = false;
        }
     
        return 1 + Max(left_height, right_height);
    }
}

bool isBalanced(struct TreeNode* root){
    if(!root) {
        return true;
    }
    
    bool is_balanced = true;
   
    printf("%d\n", GetHeight(root, &is_balanced));
    return is_balanced;
}
