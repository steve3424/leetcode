/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#define MAX_SOLUTIONS 1000

// Holds the array of solutions
typedef struct {
    int** solutions;
    int num_solutions;
} Solutions;

// Encapsulates the indices being used as the current triplet
typedef struct {
    int inds[3];
} Indices;

int Compare(void* num_1, void* num_2) {
    int* num_1_int = (int*)num_1;
    int* num_2_int = (int*)num_2;
    if(*num_1_int < *num_2_int) {
        return -1;
    }
    else if(*num_1_int > *num_2_int) {
        return 1;
    }
    else {
        return 0;
    }
}

void AddToSolutions(Solutions* solutions, int* triplet) {
    // Sort to get canonical represetation so we can easily
    // check if it already exists in the solution set
    qsort(triplet, 3, sizeof(int), Compare);
    
    // Check if solution already exists
    for(int i = 0; i < solutions->num_solutions; ++i) {
        int* current_solution = solutions->solutions[i];
        // Already in solution set, no need to add again
        if(current_solution[0] == triplet[0] &&
           current_solution[1] == triplet[1] &&
           current_solution[2] == triplet[2])
        {
            return;
        }
    }
    
    // Not in set, so add
    solutions->solutions[solutions->num_solutions] = malloc(3 * sizeof(int));
    int* solution_to_add = solutions->solutions[solutions->num_solutions];
    solution_to_add[0] = triplet[0];
    solution_to_add[1] = triplet[1];
    solution_to_add[2] = triplet[2];
    solutions->num_solutions++;
}

void EnumerateTriplets(Indices indices, int active_index, int max, 
                       int* nums, Solutions* solutions) 
{
    while(indices.inds[active_index] < max) {
        if((0 < active_index) && (1 < indices.inds[active_index] - indices.inds[active_index - 1])) {
            EnumerateTriplets(indices, active_index - 1, indices.inds[active_index],
                              nums, solutions);
        }
        else {
            int triplet[3] = {
                nums[indices.inds[0]], 
                nums[indices.inds[1]], 
                nums[indices.inds[2]]
            };
            
            if((triplet[0] + triplet[1] + triplet[2]) == 0) {
                AddToSolutions(solutions, triplet);
            }
        }
        
        indices.inds[active_index]++;
    }
}


/*
Approach 1:
Enumerate ALL triplets recursively
Add valid and unique solutions to solution set
*/
Solutions CheckAllTriplets(int* nums, int numsSize) {
    Solutions s = {0};
    s.solutions = malloc(MAX_SOLUTIONS * sizeof(int*));
    Indices indices = {0, 1, 2};
    EnumerateTriplets(indices, 2, numsSize, nums, &s);
    
    return s;
}

/*
Approach 2:
Enumerate all pairs (n^2)
Binary search for number that would make triplet sum equal to 0
*/
Solutions BinarySearchTechnique(int* nums, int numsSize) {
    Solutions s = {0};
    s.solutions = malloc(MAX_SOLUTIONS * sizeof(int*));
    
    qsort(nums, numsSize, sizeof(int), Compare);
    
    for(int i = 0; i < numsSize; ++i) {
        for(int j = i + 1; j < numsSize; ++j) {
            int need_to_find = -1 * (nums[i] + nums[j]);
            int* num_found = (int*)bsearch(&need_to_find, nums, numsSize, sizeof(int), Compare);
            if(num_found) {
                int* i_ptr = nums + i;
                int* j_ptr = nums + j;
                if(num_found != i_ptr &&
                   num_found != j_ptr)
                {
                    int triplet[3] = {
                        nums[i], 
                        nums[j], 
                        *num_found
                    };

                    AddToSolutions(&s, triplet);
                }
            }
        }
    }
    
    return s;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    if(numsSize < 3) {
        *returnSize = 0;
        return NULL;
    }
    
    /*
    Both of these approaches are too slow, but they work
    BinarySearchTechnique sometimes can be fast enough to pass
    */
    //Solutions s = CheckAllTriplets(nums, numsSize);
    Solutions s = BinarySearchTechnique(nums, numsSize);
    
    
    // All column sizes are len 3
    int* column_sizes = malloc(s.num_solutions * sizeof(int));
    for(int i = 0; i < s.num_solutions; ++i) {
        column_sizes[i] = 3;
    }
    *returnColumnSizes = column_sizes;
    
    *returnSize = s.num_solutions;
    return s.solutions;
}
