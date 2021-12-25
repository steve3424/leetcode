int removeElement(int* nums, int numsSize, int val){
    int write = 0;
    for(int i = 0; i < numsSize; ++i) {
        if(nums[i] != val) {
            nums[write++] = nums[i];
        }
    }
    
    return write;
}
