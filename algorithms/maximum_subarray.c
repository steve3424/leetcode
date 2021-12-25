
int maxSubArray(int* nums, int numsSize){
    int max = nums[0];
    int current_sum = max;
    for(int i = 1; i < numsSize; ++i) {
        int temp_sum = current_sum + nums[i];
        current_sum = temp_sum > nums[i] ? temp_sum : nums[i];
        max = current_sum > max ? current_sum : max;
    }
    return max;
}
