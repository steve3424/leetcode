
void moveZeroes(int* nums, int numsSize){
    int num_zeros = 0;
    for(int i = 0; i < numsSize; ++i) {
        if(nums[i] == 0) {
            num_zeros++;
        }
        else if(0 < num_zeros) {
            nums[i - num_zeros] = nums[i];
        }
    }
    
    int write_i = numsSize - 1;
    for(int i = 0; i < num_zeros; ++i) {
        nums[write_i--] = 0;
    }
}
