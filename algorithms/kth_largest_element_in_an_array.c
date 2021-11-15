int findKthLargest(int* nums, int numsSize, int k){
    int max_i = 0;
    int max = nums[0];
    for(int i = 0; i < k; ++i) {
        for(int j = 0; j < numsSize; ++j) {
            if(nums[j] >= max) {
                max = nums[j];
                max_i = j;
            }
        }
        
        if((i+1) == k) {
            return max;
        }
        else {
            nums[max_i] = INT_MIN;
            max = nums[0];
        }
    }
    
    return max;
}
