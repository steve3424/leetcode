int searchInsert(int* nums, int numsSize, int target){
    int start = 0;
    int end = numsSize - 1;
    int i = (start + end) / 2;
    while(start <= end) {
        if(target == nums[i]) {
            return i;
        }
        else if(target < nums[i]) {
            end = i - 1;
            i = (end + start) / 2;
        }
        else {
            start = i + 1;
            i = (end + start) / 2;
        }
    }
    return start;
}
