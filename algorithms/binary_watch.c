/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct {
    char** strings;
    int num_strings;
} WatchResult;

inline WatchResult* WatchResult_Init(int n, int k) {
    // Calculate n choose k for max number of strings needed
    int n_factorial = 1;
    for(int i = 1; i <= n; ++i) {
        n_factorial *= i;
    }
    
    int k_factorial = 1;
    for(int i = 1; i <= k; ++i) {
        k_factorial *= i;
    }
    
    int nk_factorial = 1;
    int n_minus_k = n - k;
    for(int i = 1; i <= n_minus_k; ++i) {
        nk_factorial *= i;
    }
    
    int n_choose_k = n_factorial / (k_factorial * nk_factorial); 
    
    WatchResult* res = malloc(sizeof(WatchResult));
    res->strings = malloc(n_choose_k * sizeof(char*));
    res->num_strings = 0;
    
    return res;
}

inline void PrintBits(uint16_t bits) {
    int bit_index = 15;
    for(int i = 0; i < 4; ++i) {
        for(int j = 0; j < 4; ++j) {
            if(bits & (1 << bit_index--))
            {
                printf("1");
            }
            else {
                printf("0");
            }
        }
        printf(" ");
    } 
    
    printf("\n");
}

inline uint16_t ShiftBitLeft(uint16_t bits, int bit_index) {
    bits = bits ^ (1 << bit_index);
    return bits | (1 << bit_index + 1);
}

inline uint16_t GetHours(uint16_t bits) {
    return bits >> 6;
}

inline uint16_t GetMinutes(uint16_t bits) {
    uint16_t bit_mask = 63;
    return bits & bit_mask;
}

inline char* GetWatchString(uint16_t bits) {
    uint16_t hours = GetHours(bits);
    uint16_t minutes = GetMinutes(bits);
    
    int bufsz = 6;
    char* result = calloc(bufsz, sizeof(char));
    int digits_written = snprintf(result, bufsz, "%d:", hours);
    if(minutes < 10) {
        result[digits_written++] = '0';
    }
    snprintf(result + digits_written, bufsz - digits_written, "%d", minutes);
    
    return result;
}

void Permutations(uint16_t bits, int16_t bit_index, int16_t max_index, WatchResult* results) {
    for(int i = bit_index; i < max_index; ++i) {
        uint16_t hours = GetHours(bits);
        uint16_t minutes = GetMinutes(bits);
        if(0 < (i - bit_index) && 0 < bit_index) {
            Permutations(bits, bit_index - 1, i, results);
        }
        else {
            if(hours <= 11 && minutes <= 59) {
                results->strings[results->num_strings++] = GetWatchString(bits);
            }
        }
        
        bits = ShiftBitLeft(bits, i);
    }
}

char** readBinaryWatch(int turnedOn, int* returnSize){
    if(turnedOn == 0) {
        char** result = malloc(sizeof(char*));
        *result = calloc(5, sizeof(char));
        (*result)[0] = '0';
        (*result)[1] = ':';
        (*result)[2] = '0';
        (*result)[3] = '0';
        
        *returnSize = 1;
        return result;
    }
    
    if(turnedOn > 8) {
        *returnSize = 0;
        return NULL;
    }
    
    // Set up bits
    uint16_t bits = 0;
    for(int i = 0; i < turnedOn; ++i) {
        bits = bits | (1 << i);
    }
    
    // Set up struct for results
    WatchResult* results = WatchResult_Init(10, turnedOn);
    
    int16_t max_index = 10;
    int16_t bit_index = turnedOn - 1;
    Permutations(bits, bit_index, max_index, results);
    
    
    *returnSize = results->num_strings;
    return results->strings;
}
