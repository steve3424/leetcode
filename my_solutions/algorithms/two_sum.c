typedef struct hash_entry {
    int id;
    int index;
    UT_hash_handle hh;
} hash_entry;

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int* result = malloc(2 * sizeof(int));
    *returnSize = 2;

    // n2
    /*
    for(int i = 0; i < numsSize; ++i) {
        for(int j = i + 1; j < numsSize; ++j) {
            if((nums[i] + nums[j]) == target) {
                result[0] = i;
                result[1] = j;
            }
        }
    }
    */

    struct hash_entry* table = NULL;
    for(int i = 0; i < numsSize; ++i) {
        int diff = target - nums[i];
        hash_entry* ent = NULL;
        HASH_FIND_INT(table, &diff, ent);
        if(ent) {
            result[0] = i;
            result[1] = ent->index;
            return result;
        }
        else {
            hash_entry* e = malloc(sizeof(hash_entry));
            e->id = nums[i];
            e->index = i;
            HASH_ADD_INT(table, id, e);
        }
    }
    
    return result;
}
