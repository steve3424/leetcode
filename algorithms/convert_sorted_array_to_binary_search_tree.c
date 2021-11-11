/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    struct TreeNode* node = NULL;
    
    if(numsSize > 0) {
        int middle_i = numsSize / 2;

        node = malloc(sizeof(struct TreeNode));
        if(node) {
            node->val = nums[middle_i];
            
            int left_nums_size = middle_i;
            node->left = sortedArrayToBST(nums, left_nums_size);
            
            int right_nums_size = numsSize - middle_i - 1;
            node->right = sortedArrayToBST(nums + left_nums_size + 1, right_nums_size);
        }
    }
    
    return node;
}
