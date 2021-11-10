


typedef struct {
    char** values;
    int num_values;
    int current_val;
} OrderedStream;


OrderedStream* orderedStreamCreate(int n) {
    OrderedStream* result = malloc(sizeof(OrderedStream));
    if(!result) {
        printf("Couldn't malloc for OrderedStream struct\n");
        return NULL;
    }
    
    result->values = calloc(n, sizeof(char*));
    if(!result->values) {
        printf("Couldn't malloc for values\n");
        free(result);
        return NULL;
    }
    
    result->num_values = n;
    result->current_val = 0;
    
    return result;
}

char** orderedStreamInsert(OrderedStream* obj, int idKey, char * value, int* retSize) {
    obj->values[idKey - 1] = value;
    
    char** ret = obj->values + obj->current_val;
    int prev_val = obj->current_val;
    while((obj->current_val < obj->num_values) && 
          (obj->values[obj->current_val])) 
    {
        obj->current_val++;
    }
    
    *retSize = obj->current_val - prev_val;
    return ret;
}

void orderedStreamFree(OrderedStream* obj) {
    free(obj->values);
    free(obj);
}

/**
 * Your OrderedStream struct will be instantiated and called as such:
 * OrderedStream* obj = orderedStreamCreate(n);
 * char ** param_1 = orderedStreamInsert(obj, idKey, value, retSize);
 
 * orderedStreamFree(obj);
*/
