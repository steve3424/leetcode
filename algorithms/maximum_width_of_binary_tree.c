//Definition for a binary tree node.
//struct TreeNode {
//    int val;
//    struct TreeNode *left;
//    struct TreeNode *right;
//};

// - I used a makeshift queue with of tree nodes for the BFS
// - Instead of creating a new struct to store indices along with the nodes
//   I just used a parallel array
// - I solved the overflow problem by using uint64_t and shifting down to
//   use relative indices

int widthOfBinaryTree(struct TreeNode* root){
    if(!root) {
        return 0;
    }
    
    // 2 queues:
    //      one for nodes
    //      one for index information to calculate distance at each level
    int queue_cap = 3001;
    int queue_pop = 0;
    int queue_push = 0;
    int queue_len = 0;
    struct TreeNode** queue = malloc(queue_cap * sizeof(struct TreeNode*));
    uint64_t* indices = malloc(queue_cap * sizeof(uint64_t));
    if(!queue || !indices) {
        printf("malloc gone wrong...\n");
        return 1;
    }
    
    uint64_t max_width = 0;
    queue[queue_push] = root;
    indices[queue_push] = 0;
    ++queue_push;
    ++queue_len;
    while(queue_len > 0) {
        // calculate width at this level
        uint64_t left_index  = indices[queue_pop];
        uint64_t right_index = indices[queue_push - 1];
        uint64_t current_width = (right_index + 1) - left_index;
        if(current_width > max_width) {
            max_width = current_width;
        }
        
        int num_nodes_at_level = queue_len;
        for(int i = 0; i < num_nodes_at_level; ++i) {
            struct TreeNode* current_node = queue[queue_pop];
            uint64_t current_index = indices[queue_pop];
            queue_pop = (queue_pop + 1) % queue_cap;
            --queue_len;
            
            if(current_node->left) {
                queue[queue_push] = current_node->left;
                indices[queue_push] = (2*current_index);
                queue_push = (queue_push + 1) % queue_cap;
                ++queue_len;
            }
            if(current_node->right) {
                queue[queue_push] = current_node->right;
                indices[queue_push] = (2*current_index) + 1;
                queue_push = (queue_push + 1) % queue_cap;
                ++queue_len;
            }
        }
    }
    
    return max_width;
}
