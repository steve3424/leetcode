int FindMin(int* vals, int size) {
    if(size == 0) {
        return INT_MAX;
    }
    
    int min = vals[0];
    for(int i = 1; i < size; ++i) {
        if(vals[i] < min) {
            min = vals[i];
        }
    }
    
    return min;
}


typedef struct {
    int vals[10000];
    int top;
    int min;
} MinStack;


MinStack* minStackCreate() {
    MinStack* res = malloc(sizeof(MinStack));
    if(res) {
        res->top = 0;
        res->min = INT_MAX;
    }
    
    return res;
}

void minStackPush(MinStack* obj, int val) {
    obj->vals[obj->top++] = val;
    if(val < obj->min) {
        obj->min = val;
    }
}

void minStackPop(MinStack* obj) {
    obj->top--;
    obj->min = FindMin(obj->vals, obj->top);
}

int minStackTop(MinStack* obj) {
    return obj->vals[obj->top - 1];
}

int minStackGetMin(MinStack* obj) {
    return obj->min;
}

void minStackFree(MinStack* obj) {
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/
