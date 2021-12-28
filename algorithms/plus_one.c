/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int* result = calloc(digitsSize, sizeof(int));
    
    int carry = 1;
    for(int i = digitsSize - 1; i >= 0; --i) {
        int num = digits[i] + carry;
        result[i] = num % 10;
        carry = num / 10;
    }
    
    if(carry) {
        //printf("car: %d\n", carry);
        int* new_result = calloc(digitsSize + 1, sizeof(int));
        new_result[0] = carry;
        for(int i = 1; i < digitsSize; ++i) {
            new_result[i] = result[i];
        }
        free(result);
        *returnSize = digitsSize + 1;
        return new_result;
    }
    else {
        *returnSize = digitsSize;
        return result;
    }
}
