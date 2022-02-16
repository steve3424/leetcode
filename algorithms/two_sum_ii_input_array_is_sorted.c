/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    int* result = malloc(2 * sizeof(int));
    *returnSize = 0;
    
    if(result) {
        *returnSize = 2;
        int front_i = 0;
        int back_i = numbersSize - 1;
        while(front_i < back_i) {
            int sum = numbers[front_i] + numbers[back_i];
            if(sum < target) {
                front_i++;
            }
            else if(sum > target) {
                back_i--;
            }
            else {
                result[0] = front_i + 1;
                result[1] = back_i + 1;
                break;
            }
        }
    }
    
    return result;
}
